ARCH ?= x86_64
SYS  ?= hvos

TARGET_CC = $(strip $(ARCH))-elf-gcc
#TARGET_CC = clang -target $(ARCH)-pc-$(SYS)
TARGET_AR = $(strip $(ARCH))-elf-ar


SRC_DIR = src
SYS_DIR = sys/$(strip $(SYS))
OBJ_DIR = obj
BIN_DIR = bin

INC_DIR     = include
SYS_INC     = sys
SPE_SYS_INC = sys/$(strip $(SYS))/include

LIB_NAME = $(BIN_DIR)/hvlibc.a

CRT_NAMES := crti crtn crt0
CRT_OBJS  := $(patsubst %, $(BIN_DIR)/%.o, $(CRT_NAMES))

SYSDEPS_DIR      = sysdeps
SYSDEPS_ARCH_DIR = sysdeps/$(strip $(ARCH))
SYSDEPS_GEN_DIR  = sysdeps/generic

SYSROOT_DIR ?= sysroot

SYSTEMINCL = 1
ifeq ($(SYSTEMINCL), 1)
INC_FLAGS = -isystem$(INC_DIR) -isystem$(SYS_INC) -isystem$(OBJ_DIR)/include -isystem$(SYSDEPS_ARCH_DIR) -isystem$(SYSDEPS_GEN_DIR)
else
INC_FLAGS = -I$(INC_DIR) -I$(SYS_INC) -I$(OBJ_DIR)/include -I$(SYSDEPS_ARCH_DIR) -I$(SYSDEPS_GEN_DIR)
endif

CFLAGS    = -ffreestanding -Wall -Wextra -O2 $(INC_FLAGS) -std=c11 -MMD -MP
ASFLAGS   = -ffreestanding $(INC_FLAGS) -MMD -MP

SRCS_C   := $(shell find $(SRC_DIR) -name '*.c' 2>/dev/null) \
            $(wildcard $(SYS_DIR)/*.c)

SRCS_ASM := $(wildcard $(SYSDEPS_ARCH_DIR)/*.S) $(wildcard $(SYSDEPS_ARCH_DIR)/*.s) \
            $(wildcard $(SYSDEPS_GEN_DIR)/*.S) $(wildcard $(SYSDEPS_GEN_DIR)/*.s)

SRCS_ASM := $(filter-out %crti.S %crti.s %crtn.S %crtn.s %crt0.S %crt0.s, $(SRCS_ASM))

OBJS_C   := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_C))
OBJS_ASM_UPPER := $(patsubst %.S, $(OBJ_DIR)/%.o, $(filter %.S, $(SRCS_ASM)))
OBJS_ASM_LOWER := $(patsubst %.s, $(OBJ_DIR)/%.o, $(filter %.s, $(SRCS_ASM)))
OBJS     := $(OBJS_C) $(OBJS_ASM_UPPER) $(OBJS_ASM_LOWER)
DEPS     := $(OBJS:.o=.d) $(CRT_OBJS:.o=.d)

CRTI_SRC := $(firstword $(wildcard $(SYSDEPS_ARCH_DIR)/crti.S) $(wildcard $(SYSDEPS_ARCH_DIR)/crti.s))
CRTN_SRC := $(firstword $(wildcard $(SYSDEPS_ARCH_DIR)/crtn.S) $(wildcard $(SYSDEPS_ARCH_DIR)/crtn.s))
CRT0_SRC := $(firstword $(wildcard $(SYSDEPS_ARCH_DIR)/crt0.S) $(wildcard $(SYSDEPS_ARCH_DIR)/crt0.s))

COMPILE_COMMANDS = compile_commands.json

INSTALL_DEST := $(SYSROOT_DIR)/usr/lib/libc.a

CFLAGS += --sysroot=$(SYSROOT_DIR)
CFLAGS += -D__hvos__
CFLAGS += -isystem $(SYSROOT_DIR)/usr/include

all: $(LIB_NAME) $(CRT_OBJS) $(COMPILE_COMMANDS)

$(LIB_NAME): $(OBJS)
	@mkdir -p $(dir $@)
	@echo "[AR] $(notdir $@)"
	@$(TARGET_AR) rcs $@ $(OBJS)

$(BIN_DIR)/crti.o: $(CRTI_SRC)
	@mkdir -p $(dir $@)
	@echo "[CRT] $<"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

$(BIN_DIR)/crtn.o: $(CRTN_SRC)
	@mkdir -p $(dir $@)
	@echo "[CRT] $<"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

$(BIN_DIR)/crt0.o: $(CRT0_SRC)
	@mkdir -p $(dir $@)
	@echo "[CRT] $<"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "[CC] $(notdir $<)"
	@$(TARGET_CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.S
	@mkdir -p $(dir $@)
	@echo "[AS] $(notdir $<)"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@echo "[AS] $(notdir $<)"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

$(COMPILE_COMMANDS): $(SRCS_C)
	@echo "[GEN] compile_commands.json"
	@echo "[" > $@
	@first=1; \
	for src in $(SRCS_C); do \
		abs_src=$$(realpath $$src); \
		abs_dir=$$(pwd); \
		[ $$first -eq 1 ] && first=0 || echo "  ," >> $@; \
		echo "  {" >> $@; \
		echo "    \"directory\": \"$$abs_dir\"," >> $@; \
		echo "    \"file\":      \"$$abs_src\"," >> $@; \
		echo "    \"command\":   \"$(TARGET_CC) $(CFLAGS:-I%=-isystem %) -c $$abs_src\"" >> $@; \
		echo "  }" >> $@; \
	done
	@echo "]" >> $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BIN_DIR)
	@rm -f $(COMPILE_COMMANDS)

re: fclean all

install:
	@echo "[INSTALL] $(INSTALL_DEST)"
	@cp $(LIB_NAME) $(INSTALL_DEST)
	@cp $(CRT_OBJS) $(SYSROOT_DIR)/usr/lib/

install_headers:
	@echo "[INSTALL] hvlibc includes"
	@cp -RT $(INC_DIR) $(SYSROOT_DIR)/usr/include

-include $(DEPS)

.PHONY: all clean fclean re compile_commands install install_headers

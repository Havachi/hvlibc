ARCH ?= x86_64
SYS  ?= hvos

TARGET_CC = $(strip $(ARCH))-elf-gcc
#TARGET_CC = clang -target $(ARCH)-pc-$(SYS)
TARGET_AR = $(strip $(ARCH))-elf-ar


SRC_DIR = src
SYS_DIR = sys/$(strip $(SYS))
OBJ_DIR = obj
OBJ_USER_DIR = $(OBJ_DIR)/user
OBJ_KERNEL_DIR = $(OBJ_DIR)/kernel
BIN_DIR = bin

INC_DIR     = include
SYS_INC     = sys
SPE_SYS_INC = sys/$(strip $(SYS))/include

LIB_NAME_USER = $(BIN_DIR)/libc.a
LIB_NAME_KERNEL = $(BIN_DIR)/libk.a

CRT_NAMES := crti crtn crt0
CRT_OBJS  := $(patsubst %, $(BIN_DIR)/%.o, $(CRT_NAMES))

SYSDEPS_DIR      = sysdeps
SYSDEPS_ARCH_DIR = sysdeps/$(strip $(ARCH))
SYSDEPS_GEN_DIR  = sysdeps/generic

SYSROOT_DIR ?= sysroot

GCC_INTERNAL_INC := $(shell $(TARGET_CC) -print-file-name=include)

SYSTEMINCL = 1
ifeq ($(SYSTEMINCL), 1)
INC_FLAGS = -isystem$(INC_DIR) -isystem$(SYS_INC) -isystem$(OBJ_DIR)/include -isystem$(SYSDEPS_ARCH_DIR) -isystem$(SYSDEPS_GEN_DIR)
else
INC_FLAGS = -I$(INC_DIR) -I$(SYS_INC) -I$(OBJ_DIR)/include -I$(SYSDEPS_ARCH_DIR) -I$(SYSDEPS_GEN_DIR)
endif

INC_FLAGS += -isystem $(GCC_INTERNAL_INC)


COMMON_CFLAGS = -ffreestanding -Wall -Wextra -g -O2 $(INC_FLAGS) -std=c11 -MMD -MP -m64 --sysroot=$(SYSROOT_DIR) -D__hvos__ -isystem $(SYSROOT_DIR)/usr/include

USER_CFLAGS = $(COMMON_CFLAGS) -fPIC
KERNEL_CFLAGS = $(COMMON_CFLAGS) -D__KERNEL__ -mcmodel=kernel -mno-red-zone -mno-sse -mno-mmx -mno-sse2


ASFLAGS   = -ffreestanding $(INC_FLAGS) -MMD -MP

SRCS_C   := $(shell find $(SRC_DIR) -name '*.c' 2>/dev/null) \
            $(wildcard $(SYS_DIR)/*.c)

SRCS_ASM := $(wildcard $(SYSDEPS_ARCH_DIR)/*.S) $(wildcard $(SYSDEPS_ARCH_DIR)/*.s) \
            $(wildcard $(SYSDEPS_GEN_DIR)/*.S) $(wildcard $(SYSDEPS_GEN_DIR)/*.s)

SRCS_ASM := $(filter-out %crti.S %crti.s %crtn.S %crtn.s %crt0.S %crt0.s, $(SRCS_ASM))


OBJS_USER_C := $(patsubst %.c, $(OBJ_USER_DIR)/%.o, $(SRCS_C))
OBJS_USER_ASM_UPPER := $(patsubst %.S, $(OBJ_USER_DIR)/%.o, $(filter %.S, $(SRCS_ASM)))
OBJS_USER_ASM_LOWER := $(patsubst %.s, $(OBJ_USER_DIR)/%.o, $(filter %.s, $(SRCS_ASM)))
OBJS_USER     := $(OBJS_USER_C) $(OBJS_USER_ASM_UPPER) $(OBJS_USER_ASM_LOWER)

OBJS_KERNEL_C := $(patsubst %.c, $(OBJ_KERNEL_DIR)/%.o, $(SRCS_C))
OBJS_KERNEL_ASM_UPPER := $(patsubst %.S, $(OBJ_KERNEL_DIR)/%.o, $(filter %.S, $(SRCS_ASM)))
OBJS_KERNEL_ASM_LOWER := $(patsubst %.s, $(OBJ_KERNEL_DIR)/%.o, $(filter %.s, $(SRCS_ASM)))
OBJS_KERNEL     := $(OBJS_KERNEL_C) $(OBJS_KERNEL_ASM_UPPER) $(OBJS_KERNEL_ASM_LOWER)


DEPS     := $(OBJS:.o=.d) $(CRT_OBJS:.o=.d)

OBJS_ASM_UPPER := $(patsubst %.S, $(OBJ_DIR)/%.o, $(filter %.S, $(SRCS_ASM)))
OBJS_ASM_LOWER := $(patsubst %.s, $(OBJ_DIR)/%.o, $(filter %.s, $(SRCS_ASM)))
OBJS     := $(OBJS_C) $(OBJS_ASM_UPPER) $(OBJS_ASM_LOWER)
DEPS     := $(OBJS_USER:.o=.d) $(OBJS_KERNEL:.o=.d) $(CRT_OBJS:.o=.d)

CRTI_SRC := $(firstword $(wildcard $(SYSDEPS_ARCH_DIR)/crti.S) $(wildcard $(SYSDEPS_ARCH_DIR)/crti.s))
CRTN_SRC := $(firstword $(wildcard $(SYSDEPS_ARCH_DIR)/crtn.S) $(wildcard $(SYSDEPS_ARCH_DIR)/crtn.s))
CRT0_SRC := $(firstword $(wildcard $(SYSDEPS_ARCH_DIR)/crt0.S) $(wildcard $(SYSDEPS_ARCH_DIR)/crt0.s))

INSTALLED_CRT0 := $(SYSROOT_DIR)/usr/lib/crt0.o
INSTALLED_CRTN := $(SYSROOT_DIR)/usr/lib/crtn.o
INSTALLED_CRTI := $(SYSROOT_DIR)/usr/lib/crti.o

COMPILE_COMMANDS = compile_commands.json

INSTALL_DEST_USER := $(SYSROOT_DIR)/usr/lib/libc.a
INSTALL_DEST_KERNEL := $(SYSROOT_DIR)/usr/lib/libk.a

CFLAGS += --sysroot=$(SYSROOT_DIR)
CFLAGS += -D__hvos__
CFLAGS += -isystem $(SYSROOT_DIR)/usr/include

all: $(COMPILE_COMMANDS) $(LIB_NAME_USER) $(LIB_NAME_KERNEL) $(CRT_OBJS) 

$(LIB_NAME_USER): $(OBJS_USER)
	@mkdir -p $(dir $@)
	@echo "[AR USER] $(notdir $@)"
	@$(TARGET_AR) rcs $@ $(OBJS_USER)

$(LIB_NAME_KERNEL): $(OBJS_KERNEL)
	@mkdir -p $(dir $@)
	@echo "[AR KERNEL] $(notdir $@)"
	@$(TARGET_AR) rcs $@ $(OBJS_KERNEL)

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

# USER objs compilation

$(OBJ_USER_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "[CC U] $(notdir $<)"
	@$(TARGET_CC) $(USER_CFLAGS) -c $< -o $@

$(OBJ_USER_DIR)/%.o: %.S
	@mkdir -p $(dir $@)
	@echo "[AS U] $(notdir $<)"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

$(OBJ_USER_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@echo "[AS U] $(notdir $<)"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

# KERNEL objs compilation

$(OBJ_KERNEL_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "[CC K] $(notdir $<)"
	@$(TARGET_CC) $(KERNEL_CFLAGS) -c $< -o $@

$(OBJ_KERNEL_DIR)/%.o: %.S
	@mkdir -p $(dir $@)
	@echo "[AS K] $(notdir $<)"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

$(OBJ_KERNEL_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@echo "[AS K] $(notdir $<)"
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

install_all:
	@echo "[INSTALL] $(notdir $(INSTALL_DEST_USER))"
	@cp $(LIB_NAME_USER) $(INSTALL_DEST_USER)
	@echo "[INSTALL] $(notdir $(INSTALL_DEST_KERNEL))"
	@cp $(LIB_NAME_KERNEL) $(INSTALL_DEST_KERNEL)
	@cp $(CRT_OBJS) $(SYSROOT_DIR)/usr/lib/

install_libc: $(LIB_NAME_USER) $(INSTALLED_CRT0) $(INSTALLED_CRTN) $(INSTALLED_CRTI)
	@cp $(LIB_NAME_USER) $(INSTALL_DEST_USER)

install_libk: $(LIB_NAME_KERNEL)
	@cp $(LIB_NAME_KERNEL) $(INSTALL_DEST_KERNEL)

$(INSTALLED_CRT0): $(BIN_DIR)/crt0.o
	@cp $(BIN_DIR)/crt0.o $(SYSROOT_DIR)/usr/lib/crt0.o

$(INSTALLED_CRTN): $(BIN_DIR)/crtn.o
	@cp $(BIN_DIR)/crtn.o $(SYSROOT_DIR)/usr/lib/crtn.o

$(INSTALLED_CRTI): $(BIN_DIR)/crti.o
	@cp $(BIN_DIR)/crti.o $(SYSROOT_DIR)/usr/lib/crti.o


install_headers:
	@echo "[INSTALL] hvlibc includes"
	@cp -RT $(INC_DIR) $(SYSROOT_DIR)/usr/include

-include $(DEPS)

.PHONY: all clean fclean re compile_commands install_all install_libc install_libk install_headers

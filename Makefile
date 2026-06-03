ARCH ?= x86_64
SYS  ?= hvos

TARGET_CC = $(ARCH)-elf-gcc
TARGET_AR = $(ARCH)-elf-ar

SRC_DIR = src
ARC_DIR = arch/$(ARCH)
SYS_DIR = sys/$(SYS)
OBJ_DIR = obj
BIN_DIR = bin

INC_DIR     = include
SYS_INC     = sys/
SPE_SYS_INC = sys/$(SYS)/include

LIB_NAME = $(BIN_DIR)/hvlibc.a

INC_FLAGS = -I$(INC_DIR) -I$(SYS_INC) -I$(SPE_SYS_INC) -I$(OBJ_DIR)/include
CFLAGS    = -ffreestanding -Wall -Wextra -O2 $(INC_FLAGS) -std=c11 -MMD -MP
ASFLAGS   = -ffreestanding $(INC_FLAGS)

SRCS_C   := $(wildcard $(SRC_DIR)/*.c) \
            $(wildcard $(SRC_DIR)/*/*.c) \
            $(wildcard $(SRC_DIR)/*/*/*.c) \
            $(wildcard $(SYS_DIR)/*.c)

SRCS_ASM := $(wildcard $(ARC_DIR)/*.s) \
            $(wildcard $(ARC_DIR)/*/*.s)

SRCS_C   := $(strip $(filter %.c, $(SRCS_C)))
SRCS_ASM := $(strip $(filter %.s, $(SRCS_ASM)))

OBJS_C   := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_C))
OBJS_ASM := $(patsubst %.s, $(OBJ_DIR)/%.o, $(SRCS_ASM))
OBJS     := $(OBJS_C) $(OBJS_ASM)
DEPS     := $(OBJS:.o=.d)

all: $(LIB_NAME)


$(LIB_NAME): symlinks $(OBJS)
	@mkdir -p $(dir $@)
	@echo "[AR] $(notdir $@)"
	@$(TARGET_AR) rcs $@ $(OBJS)

symlinks:
	@mkdir -p $(OBJ_DIR)/include
	@if [ ! -L $(OBJ_DIR)/include/machine ]; then \
		echo "[LN]  Creating machine/ mapping -> $(SPE_SYS_INC)"; \
		ln -sfn ../../$(SPE_SYS_INC) $(OBJ_DIR)/include/machine; \
	fi

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "[CC] $(notdir $<)"
	@$(TARGET_CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@echo "[AS] $(notdir $<)"
	@$(TARGET_CC) $(ASFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BIN_DIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean symlinks

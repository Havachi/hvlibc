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
CFLAGS    = -ffreestanding -Wall -Wextra -Werror -O2 $(INC_FLAGS) -std=c11 -MMD -MP -nostdinc
ASFLAGS   = -ffreestanding $(INC_FLAGS)

SRCS_C   := $(shell find $(SRC_DIR) -name '*.c' 2>/dev/null) \
            $(wildcard $(SYS_DIR)/*.c)

SRCS_ASM := $(shell find $(ARC_DIR) -name '*.s' 2>/dev/null)

OBJS_C   := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_C))
OBJS_ASM := $(patsubst %.s, $(OBJ_DIR)/%.o, $(SRCS_ASM))
OBJS     := $(OBJS_C) $(OBJS_ASM)
DEPS     := $(OBJS:.o=.d)

SYMLINK_SENTINEL = $(OBJ_DIR)/.symlink_done

COMPILE_COMMANDS = compile_commands.json

all: $(LIB_NAME) $(COMPILE_COMMANDS)


$(LIB_NAME): $(SYMLINK_SENTINEL) $(OBJS)
	@mkdir -p $(dir $@)
	@echo "[AR] $(notdir $@)"
	@$(TARGET_AR) rcs $@ $(OBJS)

$(SYMLINK_SENTINEL): $(SPE_SYS_INC)
	@mkdir -p $(OBJ_DIR)/include
	@echo "[LN] $(OBJ_DIR)/include/machine -> $(SPE_SYS_INC)"
	@ln -sfn ../../$(SPE_SYS_INC) $(OBJ_DIR)/include/machine
	@touch $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "[CC] $(notdir $<)"
	@$(TARGET_CC) $(CFLAGS) -c $< -o $@

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

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re compile_commands

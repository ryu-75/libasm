_BOLD      =\e[1m

# RESET list
_R          =\e[0m

# Colors
_RED      =\e[91m
_GREEN    =\e[92m
_YELLOW   =\e[93m
_BLUE     =\e[94m
_MAGENTA  =\e[35m
_CYAN     =\e[96m
_WHITE    =\e[97m

# Compiler and flags 
ASM				= nasm
CC				= gcc
ASMFLAGS		= -f elf64
CCFLAGS			= -Wall -Wextra -Werror
LIB				= ar rcs $@ $^

# Directory
SRC_DIR			= source
OBJ_DIR			= object

# Files	
ASM_SRCS			:= $(shell find $(SRC_DIR) -name '*.s')
C_SRC				= main.c
ASM_OBJS 			= $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASM_SRCS))
C_OBJ				= $(OBJ_DIR)/main.o

# Targets
all				: $(OBJ_DIR) libasm.a test

$(OBJ_DIR)		:
					@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o		: $(SRC_DIR)/%.s
					@echo "Assembling $< to $@"
					@$(ASM) $(ASMFLAGS) -o $@ $<

$(C_OBJ)		: $(C_SRC)
					$(CC) $(CCFLAGS) -c -o $@ $<


# Archive tool
libasm.a		: $(ASM_OBJS)
					@printf "\n*******************$(_BLUE)$(_BOLD) LIBASM $(_R)*******************\n\n"
					@printf "$(_BOLD)Creating archive $@ with objects:\n$(_R)"
					@ls -l $(ASM_OBJS)
					@printf "\n"
					@$(LIB) $(ASM_OBJS)
					@printf "$(_BOLD)Archive $@ created $(_GREEN)successfully.$(_R)\n\n"
					@printf "$(WHITE)$(_BOLD)Compiling process:$(_R)\n"
					@for src in $(ASM_SRCS); do \
						echo "$$src"; \
					done
					@printf "\n$(_GREEN)$(_BOLD)Compiling process finish$(_R)\n"

test			: libasm.a $(C_OBJ)
					$(CC) $(CCFLAGS) -o $@ $(C_OBJ) libasm.a

clean			:
					@echo "Cleaning up object files..."
					@rm -rf $(OBJ_DIR)
					@printf "$(_MAGENTA)Removed : $(_WHITE)./$(OBJ_DIR)\n"

fclean			: clean
					@rm -rf libasm.a test
					@printf "$(_MAGENTA)Removed : $(_WHITE)./$(NAME)\n"
					@printf "$(_GREEN)All is clean now !\n$(_R)"

re				: fclean all

.PHONY			= all clean fclean re


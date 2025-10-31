# Compiler
CC		:= cc
CFLAGS	:= -g -Wall -Wextra -Werror

# Directories
OBJDIR	:= objs
LIBDIR	:= libft

# Executable
NAME	:= Philo

# Source files
SRC := srcs/main/main.c \

# Object files
OBJ := $(patsubst srcs/%.c, $(OBJDIR)/%.o, $(SRC))

# Libft
#LIBFT	:= $(LIBDIR)/libft.a

# Colors
GREEN	:= \033[0;32m
CYAN	:= \033[0;36m
YELLOW	:= \033[1;33m
RESET	:= \033[0m

# Default rule
.DEFAULT_GOAL := all

# Build rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -lreadline
	@echo "$(CYAN)🚀 Built: $@$(RESET)"

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJDIR)
	@make -C libft clean
	@echo "$(YELLOW)🧹 Cleaned MINISHELL object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "$(YELLOW)🗑️  Removed MINISHELL binary.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

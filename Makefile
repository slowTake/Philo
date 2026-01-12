# Compiler
CC      := cc
CFLAGS  := -g -Wall -Wextra -Werror -Iincludes -pthread 

tsan: CFLAGS += -g3 -fsanitize=thread
tsan: re

# Directories
OBJDIR  := objs

# Executable
NAME    := philo

# Source files
SRC     := srcs/00_main.c \
           srcs/01_parsing.c \
           srcs/02_execution.c \
           srcs/03_mutexes.c \
           srcs/04_memory.c \
           srcs/05_error.c \
           srcs/06_cleanup.c \
           srcs/07_utils.c 

# Object files
OBJ     := $(SRC:srcs/%.c=$(OBJDIR)/%.o)

# Colors
GREEN   := \033[0;32m
CYAN    := \033[0;36m
YELLOW  := \033[1;33m
RESET   := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(CYAN)🚀 Built: $@$(RESET)"

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)🧹 Cleaned Philo object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)🗑️  Removed Philo binary.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
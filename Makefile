# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:20:54 by nbuchhol          #+#    #+#              #
#    Updated: 2025/05/11 11:07:43 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCDIR = src
OBJDIR = obj
INCDIR = includes

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

TEST_DIR = test
TEST_SRC = test.c
TEST_OBJ = $(addprefix $(OBJDIR)/, $(TEST_SRC:.c=.o))
TEST_NAME = test

SRC = main.c \
	  parsing.c \
	  init.c \
	  actions.c \
	  clean.c \
	  monitor.c \
	  philosophers.c \
	  time_utils.c \
	  utils.c

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADER = $(INCDIR)/$(NAME).h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)Executable $(NAME) successfully created!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) | $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR)  -c $< -o $@
	@echo -e "$(BLUE)Compiling $<...$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

test: $(LIBFT) $(OBJ) $(TEST_OBJ)
	@$(CC) $(CFLAGS) $(filter-out $(OBJDIR)/main.o, $(OBJ)) $(TEST_OBJ) -o $(TEST_NAME)
	@echo -e "$(GREEN)Test executable $(TEST_NAME) successfully created!$(RESET)"

$(OBJDIR)/%.o: $(TEST_DIR)/%.c $(HEADER) | $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@echo -e "$(BLUE)Compiling test file $<...$(RESET)"

run_test: test
	@echo -e "$(YELLOW)Running test with 4 philosophers, 800ms to die, 200ms to eat, 200ms to sleep...$(RESET)"
	@./$(TEST_NAME) 4 800 200 200

clean:
	@rm -rf $(OBJDIR)
	@echo -e "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all
	@echo -e "$(CYAN)Project successfully recompiled!$(RESET)"

.PHONY: all clean fclean re test run_test

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:20:54 by nbuchhol          #+#    #+#              #
#    Updated: 2025/04/28 13:50:12 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
CFLAGS = -Wall -Wextra -Werror
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

SRC = main.c

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADER = $(INCDIR)/$(NAME).h
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -o $(NAME)
	@echo -e "$(GREEN)Executable $(NAME) successfully created!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) | $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@
	@echo -e "$(BLUE)Compiling $<...$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@echo -e "$(PURPLE)Compiling libft...$(RESET)"
	@make -C $(LIBFTDIR)
	@echo -e "$(PURPLE)Libft successfully compiled!$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@echo -e "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo -e "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all
	@echo -e "$(CYAN)Project successfully recompiled!$(RESET)"
	
.PHONY: all clean fclean re
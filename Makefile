# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 11:39:08 by ctaboada          #+#    #+#              #
#    Updated: 2025/03/25 15:13:57 by ctaboada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRCDIR = .
OBJDIR = obj
LIBFTDIR = libft
INCLUDES = -Iincludes -I$(LIBFTDIR)/includes

# Source files and objects
SRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/commands/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Library
LIBFT = $(LIBFTDIR)/libft.a

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Executable $(NAME) created successfully!"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@if not exist "$(OBJDIR)\commands" mkdir "$(OBJDIR)\commands"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@rd /s /q $(OBJDIR) 2>nul || cmd /c exit 0
	@$(MAKE) -s -C $(LIBFTDIR) clean
	@echo "Object files removed."

fclean: clean
	@del $(NAME) 2>nul || cmd /c exit 0
	@$(MAKE) -s -C $(LIBFTDIR) fclean
	@echo "Executable $(NAME) removed."


re: fclean all

.PHONY: all clean fclean re
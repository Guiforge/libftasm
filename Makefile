# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 23:02:42 by gpouyat           #+#    #+#              #
#    Updated: 2018/10/17 16:15:24 by gpouyat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS          = -Wall -Wextra -Werror

ifeq ($(DEV),yes)
    CFLAGS              += -g3
endif

ifeq ($(SAN),yes)
    CFLAGS              += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif


NAME=libfts.a
NAME_TEST=test
OBJS_DIR=./objs
SRCDIR=./srcs/
ARCH=macho64
SRCS=ft_bzero.s ft_strlen.s ft_isalpha.s ft_isdigit.s ft_isalnum.s ft_isascii.s \
		ft_isprint.s ft_toupper.s ft_tolower.s ft_puts.s ft_strcat.s ft_memset.s \
		ft_memcpy.s ft_strdup.s ft_memalloc.s ft_strcpy.s ft_cat.s ft_strncpy.s \
		ft_putstr.s ft_putstr_fd.s

OBJS=$(SRCS:%.s=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
		mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCDIR)%.s
		nasm -f $(ARCH) $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TEST)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c -o test -I . $(NAME)

retest: re test

.phony: all clean fclean re test retest

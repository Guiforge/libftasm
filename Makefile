# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 23:02:42 by gpouyat           #+#    #+#              #
#    Updated: 2018/08/21 12:07:48 by gpouyat          ###   ########.fr        #
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

SRCS_TEST=test_bzero.c test_strlen.c test_puts.c test_strcat.c
SRCSDIR_TEST=./tests
SRCS_TESTS=$(SRCS_TEST:%.c=$(SRCSDIR_TEST)/%.c)

NAME=libfts.a
OBJS_DIR=./objs
SRCDIR=./srcs/
ARCH=macho64
SRCS=ft_bzero.s ft_strlen.s ft_isalpha.s ft_isdigit.s ft_isalnum.s ft_isascii.s \
		ft_isprint.s ft_toupper.s ft_tolower.s ft_puts.s ft_strcat.s
# ft_strcat.s ft_islower.s ft_isupper.s \
#          ft_isprint.s ft_toupper.s ft_tolower.s ft_strlen.s \
#          ft_memset.s ft_memcpy.s ft_puts.s ft_strdup.s ft_strcpy.s ft_cat.s \
#          ft_strchr.s ft_strrchr.s ft_isalnum.s ft_isascii.s ft_strcmp.s \
#          ft_memalloc.s ft_memdel.s ft_strnew.s ft_strncmp.s

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

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(SRCS_TESTS) -o test -I . -I $(SRCSDIR_TEST)/. $(NAME)

retest: re test

.phony: all clean fclean re test retest
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 13:06:09 by sleung            #+#    #+#              #
#    Updated: 2017/03/03 13:03:30 by sleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -g

INCDIR = -I ft_printf.h

RM = rm -f

SRC = ft_printf.c ft_printf_cs.c ft_printf_id.c ft_printf_xo.c \
	  ft_printf_pp.c ft_printf_u.c ft_printf_wcs.c \
	  check_conv.c check_flags.c read_data.c count_spaces.c \
	  handle_sign.c handle_flags.c handle_sharp.c handle_modifiers.c \
	  handle_wildcard.c \
	  ft_atoi.c ft_itoa_base.c ft_itoa_unsigned.c ft_memset.c ft_strjoin.c \
	  ft_strlen.c ft_strnew.c ft_strdel.c ft_intlen.c ft_stricpy.c \
	  ft_putstr.c ft_putstrdel.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INCDIR) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean

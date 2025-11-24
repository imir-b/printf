# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 21:47:42 by vbleskin          #+#    #+#              #
#    Updated: 2025/11/24 03:32:01 by vbleskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbrbase.c \
		ft_putnbr.c ft_putstr.c ft_putptr.c
OBJ =	$(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

NAME = libftprintf.a
INCLUDES = -Iinclude

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : 		$(NAME)

$(NAME) :		$(OBJ)
			$(AR) $@ $^

clean :
			$(RM) $(OBJ)

fclean :	clean
			$(RM) $(NAME)

re :		fclean $(NAME)
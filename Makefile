# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 21:47:42 by vbleskin          #+#    #+#              #
#    Updated: 2025/11/16 23:12:47 by vbleskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/ft_printf.c src/ft_putchar.c src/ft_putnbr.c src/ft_putnbrbase.c \
		src/ft_putnbr.c src/ft_putstr.c src/ft_putptr.c
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
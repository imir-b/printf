# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 21:47:42 by vbleskin          #+#    #+#              #
#    Updated: 2025/12/03 10:28:37 by vbleskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	printf.c parsing.c utils_write.c utils.c
OBJ =	$(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

NAME = libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : 		$(NAME)

$(NAME) :		$(OBJ)
			$(AR) $@ $^

clean :
			$(RM) $(OBJ)

fclean :	clean
			$(RM) $(NAME)

re :		fclean $(NAME)
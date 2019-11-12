# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 17:55:40 by stbaleba          #+#    #+#              #
#    Updated: 2019/11/12 18:26:18 by stbaleba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra

NAME=libftprintf.a
INC= -Iincludes
FILES=ft_printf.c \
		./srcs/ft_parse.c \
		./srcs/ft_printf_utils.c \
		./srcs/ft_printf_utils2.c \
		./srcs/ft_putnbr.c \
		./srcs/ft_putstr.c 
OBJ=$(FILES:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) ./includes/libftprintf.h
			ar rc $(NAME) $(OBJ)
.c.o: $(FILES)
		$(CC) $(CFLAGS) -c $(INC) $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)


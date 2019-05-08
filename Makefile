# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:11:22 by lgarczyn          #+#    #+#              #
#    Updated: 2019/05/01 00:09:33 by brjorgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	get_next_line.c \
		field.c \
		read_file.c \
		read_tetri.c \
		validate_tetri.c \
		display.c \
		fillit.c \
		tools.c \
		main.c

HEADERS =	libft/libft.h \
			get_next_line.h \
			fillit.h \

OBJ = $(SRC:.c=.o)

INC = -I libft/

LIB = -L libft/ -lft

FLG = -Wall -Wextra -Werror

all: $(NAME)

libft/libft.a:
	cd libft && make

$(NAME):$(OBJ) libft/libft.a
	gcc $(OBJ) $(FLG) $(LIB) -o $(NAME)

%.o: %.c $(HEADERS)
	gcc $(INC) $(FLG) -c $< -o $@

clean:
	rm -rf $(OBJ)
	cd libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd libft && make fclean

re: fclean all

.SUFFIXES:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:44:13 by brjorgen          #+#    #+#              #
#    Updated: 2019/04/26 17:50:10 by lgarczyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra

NAME =		libft.a

SRCS =		./ft_strlen.c		\
			./ft_atoi.c			\
			./ft_iswhitespace.c	\
			./ft_memmove.c		\
			./ft_strcat.c		\
			./ft_strjoin.c		\
			./ft_strrchr.c		\
			./ft_bzero.c		\
			./ft_memalloc.c		\
			./ft_memset.c		\
			./ft_strchr.c		\
			./ft_strlen.c		\
			./ft_strstr.c		\
			./ft_isalnum.c		\
			./ft_memccpy.c		\
			./ft_putchar.c		\
			./ft_strclr.c		\
			./ft_strmap.c		\
			./ft_tolower.c		\
			./ft_isalpha.c		\
			./ft_memchr.c		\
			./ft_putchar_fd.c	\
			./ft_strcmp.c		\
			./ft_strncat.c		\
			./ft_toupper.c		\
			./ft_isascii.c		\
			./ft_memcmp.c		\
			./ft_putendl_fd.c	\
			./ft_strcpy.c		\
			./ft_strncmp.c		\
			./ft_isdigit.c		\
			./ft_memcpy.c		\
			./ft_putstr.c		\
			./ft_strdup.c		\
			./ft_strncpy.c		\
			./ft_isprint.c		\
			./ft_memdel.c		\
			./ft_xmalloc.c		\
			./ft_putstr_fd.c	\
			./ft_striteri.c		\
			./ft_strnew.c		\
			./ft_striter.c		\
			./ft_strdel.c		\
			./ft_strnstr.c		\
			./ft_strmapi.c		\
			./ft_strequ.c		\
			./ft_strnequ.c		\
			./ft_strsub.c		\
			./ft_strtrim.c		\
			./ft_strsplit.c		\
			./ft_putendl.c		\
			./ft_putnbr.c		\
			./ft_strlcat.c		\
			./ft_lstadd.c		\
			./ft_lstdel.c		\
			./ft_lstdelone.c	\
			./ft_lstiter.c		\
			./ft_lstnew.c		\
			./ft_lstmap.c		\
			./ft_itoa.c			\
			./ft_putnbr_fd.c	\
			./ft_revstr.c		\
			./ft_intlen.c		\
			./ft_repeatchar.c	\
			./ft_lstsize.c

OBJ =		$(SRCS:%.c=%.o)

HEADER = libft.h

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS)

all :		$(NAME)

$(NAME) :	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean :
			rm -rf $(OBJ)

fclean :	clean
			rm -rf $(NAME)

re : 		fclean all

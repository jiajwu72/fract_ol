
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:59:52 by jwu               #+#    #+#              #
#    Updated: 2018/01/11 20:15:43 by jwu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_atoi.c		\
		ft_bzero.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_lstadd.c	\
		ft_lstdel.c	\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstmap.c	\
		ft_lstnew.c	\
		ft_memalloc.c	\
		ft_memccpy.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memdel.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar.c	\
		ft_putchar_fd.c\
		ft_putendl.c	\
		ft_putendl_fd.c\
		ft_putnbr.c	\
		ft_putnbr_fd.c	\
		ft_putstr.c		ft_putint.c\
		ft_putstr_fd.c	\
		ft_strcat.c	\
		ft_strchr.c	\
		ft_strcmp.c	\
		ft_strcpy.c	\
		ft_strclr.c	\
		ft_strdel.c	\
		ft_strdup.c	\
		ft_strequ.c	\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	ft_print_t_int.c\
		ft_strlen.c		ft_sstrlen.c\
		ft_strmap.c		ft_sstrcpy.c\
		ft_strmapi.c	\
		ft_strncat.c	ft_intnew.c\
		ft_strncmp.c	ft_free_iint.c\
		ft_strncpy.c	ft_iintlen.c\
		ft_strnequ.c	ft_free_sstr.c\
		ft_strnew.c		ft_intcpy.c ft_one_str.c\
		ft_strnstr.c	ft_isnbr.c\
		ft_strrchr.c	ft_intcat.c\
		ft_strsplit.c	ft_cnt_parts.c ft_hexa_to_int.c\
		ft_strstr.c		ft_print_tt_char.c ft_print_tt_int.c\
		ft_strsub.c		ft_replacechar.c\
		ft_strtrim.c	ft_haschar.c ft_isint.c\
		ft_tolower.c	get_next_line.c ft_tt_intnew.c ft_sstrnew.c\
		ft_toupper.c	ft_endl.c ft_firstch.c\
		ft_strappend.c	ft_strremove.c ft_indexof.c ft_strmerge.c\
		ft_intlen.c 	ft_puiss.c ft_int_to_hexa.c ft_tt_intlen.c\

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror
CC = gcc
NAME = libft.a
HEAD = libft.h

$(NAME):$(OBJ)
	$(CC) -c $(CFLAG) $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all
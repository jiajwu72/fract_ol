#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 16:12:30 by jwu               #+#    #+#              #
#    Updated: 2018/01/26 16:12:31 by jwu              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ./fractol.h
SRC = cal_color.c key_hook.c mouse_hook.c draw.c main.c key_hook2.c tool.c cal_color2.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(HEAD) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

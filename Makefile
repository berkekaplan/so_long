# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 22:00:09 by mkaplan           #+#    #+#              #
#    Updated: 2023/06/01 10:16:47 by mkaplan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OBJECTS = $(shell find ./ -name "*.o")
A = $(shell find ./ -name "*.a")
CC = gcc

FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -g

CFILES = $(shell find . -name "*.c")

all:
	@make -C ./libft
	@make -C ./ft_printf
	@make -C ./minilibx
	$(CC) ./src/*.c ./libft/libft.a ./ft_printf/libftprintf.a $(FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)
	@echo "Removed [$(OBJECTS)]"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(A)
	@echo "Removed [$(NAME)]"

re: fclean all

.PHONY: all clean fclean re
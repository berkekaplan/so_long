# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaplan <@student.42kocaeli.com.tr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 21:57:30 by mkaplan           #+#    #+#              #
#    Updated: 2023/03/27 21:57:31 by mkaplan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = $(shell find . -type f ! -name "ft_lst*.c" -name "ft_*.c")

OBJ = $(SRC:.c=.o)
BSRC	= $(wildcard ft_lst*.c)
B_OBJ	= $(BSRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

all: $(NAME)

bonus: $(OBJ) $(B_OBJ)
	@ar -rcs $(NAME) $(OBJ) $(B_OBJ)
clean: 
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 05:56:08 by nsierra-          #+#    #+#              #
#    Updated: 2013/12/14 10:41:41 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

SRC = get_next_line.c hot_race.c ft_strcmp.c ft_putendl.c ft_putstr.c		   \
	  ft_putchar.c main.c search.c

OBJ = $(SRC:.c=.o)

CC = llvm-gcc

CFLAGS = -Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

test: fclean all

re: fclean all

.PHONY: compile_lib

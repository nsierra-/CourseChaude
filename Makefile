# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 20:50:12 by nsierra-          #+#    #+#              #
#    Updated: 2013/12/15 21:04:19 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

SRC = free.c ft_hashich.c ft_pop_elem.c ft_putendl.c ft_putstr.c ft_strcmp.c  \
		gnl.c hotrace.c search.c

OBJ = $(SRC:.c=.o)

CC = llvm-gcc

CFLAGS = -O3 -Wall -Wextra -Werror

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

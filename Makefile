# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 05:56:08 by nsierra-          #+#    #+#              #
#    Updated: 2013/12/14 02:10:07 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

SRC = get_next_line.c hot_race.c ft_strchr.c ft_strjoin.c ft_strlen.c		   \
	  ft_strnew.c ft_strsub.c ft_strcat.c ft_strcmp.c ft_strend.c
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -Ilibft

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

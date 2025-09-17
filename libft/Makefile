# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oussama <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 16:51:24 by oussama           #+#    #+#              #
#    Updated: 2025/09/12 18:35:45 by oussama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG = -Wall -Wextra -Werror

SRC1 = $(wildcard ./part1/*.c)
SRC2 = $(wildcard ./part2/*.c)
SRC3 = $(wildcard ./partbonus/*.c)
SRC = $(SRC1) $(SRC2) $(SRC3)

OBJ = $(SRC:.c=.o)

all: libft.a

libft.a: $(OBJ)
	ar -crs $@ $(OBJ) 

%.o: %.c libft.h
	cc -g $(FLG) -I. -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean: clean
	rm -f libft.a

mk: libft.a
	cc -g $(FLG) main.c  libft.a

re: fclean all

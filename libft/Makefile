# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oussama <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 16:51:24 by oussama           #+#    #+#              #
#    Updated: 2025/08/25 20:09:19 by oussama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG = -Wall -Wextra -Werror
SRC = $(filter-out main.c, $(wildcard *.c))
OBG = $(SRC:.c=.o)


all: libft.a

libft.a: $(OBG)
	ar -crs $@ $(OBG) 

%.o: %.c libft.h
	cc $(FLG) -c $< -o $@

clean:
	rm -f $(OBG)
	rm -f libft.h.gch

fclean: clean
	rm -f libft.a

mk: libft.a
	cc $(FLG) main.c  libft.a

re: fclean all

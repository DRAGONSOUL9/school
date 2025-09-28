# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oussama <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 02:55:54 by oussama           #+#    #+#              #
#    Updated: 2025/09/28 03:19:13 by oussama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c
OBG = $(SRC:.c=.o)
NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBG)
	ar -crs $@ $^

%.o: %.c
	cc $(FLG) -c $^ -o $@

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all

mk: $(NAME)
	cc $(FLG) $(NAME)

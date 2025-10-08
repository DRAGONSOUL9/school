# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oussama <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 04:49:40 by oussama           #+#    #+#              #
#    Updated: 2025/10/08 12:25:15 by oussama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putnbr_base.c
OBG = $(SRC:.c=.o)
NAME = libftprintf.a
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBG) $(LIBFT)
	ar -crs $(NAME) $(OBG)

$(LIBFT): ./libft/Makefile
	make -C ./libft

%.o: %.c
	cc $(FLG) -g -I ./libft -c $< -o $@

clean:
	rm -rf $(OBG)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out
	make fclean -C ./libft

re: fclean all

mk: $(NAME)
	cc $(FLG) -g -I ./libft test.c $(NAME) $(LIBFT)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oussama <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 04:49:40 by oussama           #+#    #+#              #
#    Updated: 2025/10/04 17:29:31 by oussama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
OBG = $(SRC:.c=.o)
NAME = libftprintf.a
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBG) $(LIBFT)
	ar -crs $(NAME) $(OBG) ./libft/*.o

$(LIBFT): ./libft/Makefile
	$(MAKE) -C ./libft

%.o: %.c
	cc $(FLG) -I./libft -c $< -o $@

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all

mk: $(NAME)
	cc $(FLG) -g -I./libft $(NAME) test.c

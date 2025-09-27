# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oussama <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 16:51:24 by oussama           #+#    #+#              #
#    Updated: 2025/09/22 00:03:40 by oussama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG = -Wall -Wextra -Werror

SRC = $(wildcard ./*.c)
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
             ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $@ $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar -crs $(NAME) $(OBJ) $(BONUS_OBJ)

%.o: %.c
	cc -g $(FLG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libft.a

mk: libft.a
	cc -g $(FLG) main.c  libft.a

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxell <maxell@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 18:08:30 by maxell            #+#    #+#              #
#    Updated: 2020/12/17 16:05:58 by maxell           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
# NAME = libftprintf.a
HEAD = ft_printf.h

SRC = ft_printf.c \
	  str.c \
	  processor.c \
	  types.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra #-c

all: $(NAME)
$(NAME):
	gcc -Wall -Werror -Wextra -g *.c -o ft_printf_2

# $(NAME): $(OBJ)
# 	ar rc $(NAME) $(OBJ)
# 	ranlib $(NAME)

# %.o: %.c $(HEAD)
# 	gcc $(CFLAGS) $< -o $@ -I.

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxell <maxell@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 18:08:30 by maxell            #+#    #+#              #
#    Updated: 2020/12/21 19:12:30 by maxell           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEAD = ft_printf.h 

SRC =   ft_isdigit.c	ft_parser.c	ft_strlen.c	\
		ft_itoa.c	ft_print_p.c	ft_processor.c	ft_types.c \
		ft_printf.c	ft_str.c	ft_utils.c 
OBJ = ${SRC:.c=.o}

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(MAKE) all -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	
all: $(NAME)

compile:
	gcc -Wall -Werror -Wextra -g *.c -o ft_printf

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
    

re: fclean all

.PHONY: all clean fclean re bonus

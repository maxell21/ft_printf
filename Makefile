# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxell <maxell@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 18:08:30 by maxell            #+#    #+#              #
#    Updated: 2021/01/13 20:13:14 by maxell           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEAD = ft_printf.h 

SRC =   ft_parser.c \
		ft_print_p.c \
		ft_print_d.c \
		ft_print_x.c \
		ft_print_u.c \
		ft_processor.c \
		ft_printf.c	\
		ft_str.c	\
		ft_utils.c \

OBJ = ${SRC:.c=.o}

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(MAKE) all -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $?
	
all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
    

re: fclean all

.PHONY: all clean fclean re bonus

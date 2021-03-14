/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:49:27 by maxell            #+#    #+#             */
/*   Updated: 2021/01/13 17:48:23 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef struct	s_parse
{
	int			zero;
	int			negative;
	int			wi;
	int			pr;
	int			length;
	int			dot;
	int			is_neg;
	int			fl;
	int			large_x;
	int			star;
	int			neg_star;
	char		type;
}				t_parse;

int				ft_printf(const char *str, ...);
int				print_args(const char *str, va_list args);
int				process_arg(va_list args, t_parse *ag_str);

int				ft_istype(char c);

int				print_void(char c, int width);
int				ft_abs(int num);
void			ft_putstr_width(char *s, int width);
void			ft_puthex(unsigned long n, int fl, int fl2);

int				print_str(va_list args, t_parse *ag_str);
int				print_char(va_list arg, t_parse *ag_str);
int				print_pointer(va_list args, t_parse *ag_str);
int				print_digit(va_list args, t_parse *ag_str);
int				print_unsigned(va_list args, t_parse *st);
int				print_x(va_list args, t_parse *st);
int				print_large_x(va_list args, t_parse *st);

int				skip_flags(char *str, int i, t_parse *arg);
int				get_number(char *str, int i);
int				ft_num_len(long num);
int				count_len(unsigned long number);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:54:04 by maxell            #+#    #+#             */
/*   Updated: 2020/12/26 20:29:57 by maxell           ###   ########.fr       */
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
	int			width;
	int			precision;
	int			length;
	int			dot;
	int			is_neg;
	char		type;
}				t_parse;

int				ft_printf(const char *str, ...);
int				print_args(const char *str, va_list args);
int				process_arg(va_list args, t_parse *ag_str);

int				ft_istype(char c);

int				print_void(char c, int width);
int				ft_abs(int num);
void			ft_putstr_width(char *s, int width);
void			ft_puthex(unsigned long n);

int				print_str(va_list args, t_parse *ag_str);
int				print_char(va_list arg, t_parse *ag_str);
int				print_pointer(va_list args, t_parse *ag_str);
int				print_digit(va_list args, t_parse *ag_str);

int				skip_flags(char *str, int i, t_parse *arg);
int				get_number(char *str, int i);
int				ft_num_len(int num);

#endif

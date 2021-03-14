/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:49:39 by maxell            #+#    #+#             */
/*   Updated: 2021/01/11 20:59:57 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' ||\
		c == 'd' || c == 'i' || c == 'u' ||\
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int		print_percent(t_parse *ag_str)
{
	if (ag_str->wi && !ag_str->zero && !ag_str->negative)
		print_void(' ', ag_str->wi - 1);
	else if (ag_str->wi && ag_str->zero && !ag_str->negative)
		print_void('0', ag_str->wi - 1);
	ft_putchar('%');
	if (ag_str->wi && ag_str->negative)
		print_void(' ', ag_str->wi - 1);
	return ((ag_str->wi ? ag_str->wi : 1));
}

static void		ft_condiitions(t_parse *st)
{
	if (st->wi < 0)
	{
		st->wi = ft_abs(st->wi);
		st->negative = 1;
	}
	if (st->pr < 0)
	{
		st->dot = 0;
		st->neg_star = 1;
	}
	(st->dot) ? (st->zero = 0) : 0;
}

int				process_arg(va_list args, t_parse *ag_str)
{
	char	type;

	type = ag_str->type;
	ft_condiitions(ag_str);
	if (type == 'c')
		ag_str->length = print_char(args, ag_str);
	if (type == 37)
		ag_str->length = print_percent(ag_str);
	else if (type == 's')
		ag_str->length = print_str(args, ag_str);
	else if (type == 'p')
		ag_str->length = print_pointer(args, ag_str);
	else if (type == 'd' || type == 'i')
		ag_str->length = print_digit(args, ag_str);
	else if (type == 'u')
		ag_str->length = print_unsigned(args, ag_str);
	else if (type == 'x')
		ag_str->length = print_x(args, ag_str);
	else if (type == 'X')
		ag_str->length = print_large_x(args, ag_str);
	return (ag_str->length);
}

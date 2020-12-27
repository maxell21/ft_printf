/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student->42->fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:37:04 by maxell            #+#    #+#             */
/*   Updated: 2020/12/27 19:42:37 by maxell           ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num(int num, int len, t_parse *st)
{
	int count;
	int	wi;
	int	pr;

	count = 0;
	wi = st->width;
	(st->dot) ? (st->zero = 0) : 0;
	(st->negative) ? (st->zero = 0) : 0;
	(st->is_neg && st->precision > len && wi) ? (st->precision++) : 0;
	pr = st->precision;
	if (st->negative && wi)
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		(st->dot) ? count += print_void('0', pr - len) : 0;
		ft_putnbr_fd(num, 1);
		count += print_void(' ', wi - ((pr > len) ? pr : len));
	}
	else if (st->zero && wi && !st->dot)
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		count += print_void('0', wi - len);
		ft_putnbr_fd(num, 1);
	}
	else if (wi && !st->dot)
	{
		count += print_void(' ', wi - len);
		(st->is_neg) ? ft_putchar('-') : 0;
		ft_putnbr_fd(num, 1);
	}
	else if (wi && st->dot)
	{
		count += print_void(' ', wi - ((pr > len) ? pr : len));
		(st->is_neg) ? ft_putchar('-') : 0;
		count += print_void('0', (pr > len) ? pr - len : 0);
		ft_putnbr_fd(num, 1);
	}
	else if (st->dot)
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		(st->is_neg) ? len-- : 0;
		count += print_void('0', pr - len);
		ft_putnbr_fd(num, 1);
	}
	else
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		ft_putnbr_fd(num, 1);
	}
	return (count);
}

int			print_digit(va_list args, t_parse *st)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	len = ft_num_len(num);
	if (num < 0)
	{
		st->is_neg = 1;
		num *= -1;
	}
	len += print_num(num, len, st);
	return (len);
}

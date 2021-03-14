/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:37:04 by maxell            #+#    #+#             */
/*   Updated: 2021/01/11 20:58:44 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pt_3(int num, int len, int count, t_parse *st)
{
	if (st->negative && st->neg_star)
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		(st->wi && st->pr > len) ? (count += print_void('0', st->pr - len)) : 0;
		ft_putnbr(num, st->fl);
		count += print_void(' ', st->wi - len);
	}
	else if (st->negative && !st->neg_star)
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		(st->is_neg && st->star && !st->wi) ? (st->pr++) : 0;
		(st->dot) ? count += print_void('0', st->pr - len) : 0;
		ft_putnbr(num, st->fl);
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
	}
	else if (st->zero)
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		count += print_void('0', st->wi - len);
		ft_putnbr(num, st->fl);
	}
	return (count);
}

static int	print_pt2(int num, int len, int count, t_parse *st)
{
	if (st->wi && !st->dot)
	{
		count += print_void((st->zero ? '0' : ' '), st->wi - len);
		(st->is_neg) ? ft_putchar('-') : 0;
	}
	else if (st->wi && st->dot)
	{
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
		(st->is_neg) ? ft_putchar('-') : 0;
		count += print_void('0', (st->pr > len) ? st->pr - len : 0);
	}
	else if (st->dot)
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		(st->is_neg) ? len-- : 0;
		count += print_void('0', st->pr - len);
	}
	ft_putnbr(num, st->fl);
	return (count);
}

static int	print_num(int num, int len, int count, t_parse *st)
{
	if ((st->negative && st->neg_star) || (st->negative && !st->neg_star) || \
		(st->zero && st->wi))
		count += print_pt_3(num, len, count, st);
	else if ((st->wi && !st->dot) || (st->wi && st->dot) || st->dot)
		count += print_pt2(num, len, count, st);
	else
	{
		(st->is_neg) ? ft_putchar('-') : 0;
		ft_putnbr(num, st->fl);
	}
	return (count);
}

int			print_digit(va_list args, t_parse *st)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	len = ft_num_len(num);
	if (!num && st->dot && !st->pr)
	{
		st->fl = 1;
		len -= 1;
	}
	if (num < 0)
	{
		st->is_neg = 1;
		(st->pr >= len && st->wi) ? (st->pr++) : 0;
		num *= -1;
	}
	(st->neg_star && st->pr > st->wi && num) ? (st->pr = 0) : 0;
	(st->neg_star && st->wi && st->pr > len) ? (st->pr = 0) : 0;
	len += print_num(num, len, 0, st);
	return (len);
}

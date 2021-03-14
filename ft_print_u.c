/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:14:14 by maxell            #+#    #+#             */
/*   Updated: 2021/01/11 18:01:59 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num(unsigned long long num)
{
	int	len;

	len = 1;
	if (num == 0)
		return (len);
	while (num >= 10)
	{
		num /= 10;
		len += 1;
	}
	return (len);
}

static void	ft_putlong(unsigned long long n, int fl)
{
	if (fl == 1)
		return ;
	if (n == 4294967295)
	{
		ft_putchar('4');
		ft_putlong(294967295, fl);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putlong(n * (-1), fl);
	}
	else
	{
		if (n >= 10)
			ft_putlong(n / 10, fl);
		ft_putchar((n % 10) + 48);
	}
}

static int	print_pt2(unsigned long num, int len, int count, t_parse *st)
{
	if (st->wi && !st->dot)
		count += print_void(' ', st->wi - len);
	else if (st->wi && st->dot)
	{
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
		count += print_void('0', (st->pr > len) ? st->pr - len : 0);
	}
	else if (st->dot)
	{
		(st->is_neg) ? len-- : 0;
		count += print_void('0', st->pr - len);
	}
	ft_putlong(num, st->fl);
	return (count);
}

static int	print_num(unsigned long num, int len, int count, t_parse *st)
{
	if (st->negative && st->wi)
	{
		(st->dot) ? count += print_void('0', st->pr - len) : 0;
		ft_putlong(num, st->fl);
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
	}
	else if (st->zero && st->wi && !st->dot)
	{
		count += print_void('0', st->wi - len);
		ft_putlong(num, st->fl);
	}
	else if ((st->wi && !st->dot) || (st->wi && st->dot) || st->dot)
		count += print_pt2(num, len, count, st);
	else
		ft_putlong(num, st->fl);
	return (count);
}

int			print_unsigned(va_list args, t_parse *st)
{
	unsigned int	num;
	int				len;

	num = va_arg(args, unsigned long);
	len = ft_num(num);
	if (!num && st->dot && !st->pr)
	{
		st->fl = 1;
		len -= 1;
	}
	len += print_num(num, len, 0, st);
	return (len);
}

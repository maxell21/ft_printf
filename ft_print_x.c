/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:50:33 by maxell            #+#    #+#             */
/*   Updated: 2021/01/11 17:59:28 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pt2(unsigned int num, int len, int count, t_parse *st)
{
	if (st->wi && !st->dot)
		count += print_void(' ', st->wi - len);
	else if (st->wi && st->dot)
	{
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
		count += print_void('0', (st->pr > len) ? st->pr - len : 0);
	}
	else if (st->dot)
		count += print_void('0', st->pr - len);
	ft_puthex((unsigned long)num, st->fl, st->large_x);
	return (count);
}

static int	print_num(unsigned int num, int len, int count, t_parse *st)
{
	if (st->negative && st->wi)
	{
		(st->dot) ? count += print_void('0', st->pr - len) : 0;
		ft_puthex((unsigned long)num, st->fl, st->large_x);
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
	}
	else if (st->zero && st->wi && !st->dot)
	{
		count += print_void('0', st->wi - len);
		ft_puthex((unsigned long)num, st->fl, st->large_x);
	}
	else if ((st->wi && !st->dot) || (st->wi && st->dot) || st->dot)
		count += print_pt2(num, len, count, st);
	else
		ft_puthex((unsigned long)num, st->fl, st->large_x);
	return (count);
}

int			print_x(va_list args, t_parse *st)
{
	unsigned int	ptr;
	int				len;

	ptr = va_arg(args, unsigned int);
	len = count_len(ptr);
	if (!ptr && st->dot && !st->pr)
	{
		st->fl = 1;
		len -= 1;
	}
	(st->dot) ? (st->zero = 0) : 0;
	(st->negative) ? (st->zero = 0) : 0;
	len += print_num(ptr, len, 0, st);
	return (len);
}

int			print_large_x(va_list args, t_parse *st)
{
	unsigned int	ptr;
	int				len;

	ptr = va_arg(args, unsigned int);
	len = count_len(ptr);
	st->large_x = 1;
	if (!ptr && st->dot && !st->pr)
	{
		st->fl = 1;
		len -= 1;
	}
	len += print_num(ptr, len, 0, st);
	return (len);
}

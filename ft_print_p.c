/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:47:49 by maxell            #+#    #+#             */
/*   Updated: 2021/01/11 17:58:41 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_len(unsigned long number)
{
	int i;

	i = 1;
	while (number /= 16)
		i++;
	return (i);
}

static int	print_ptr2(unsigned long num, int len, int count, t_parse *st)
{
	int fl;

	fl = 0;
	if (st->wi && !st->dot)
		count += print_void(' ', st->wi - len);
	else if (st->pr > st->wi)
	{
		count += write(1, "0x", 2);
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
		count += print_void('0', (st->pr > len) ? st->pr - len : 0);
		fl = 1;
	}
	else if (st->wi && st->dot)
	{
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
		count += print_void('0', (st->pr > len) ? st->pr - len : 0);
	}
	else if (st->dot)
		count += print_void('0', st->pr - len);
	(fl == 0) ? (count += write(1, "0x", 2)) : 0;
	ft_puthex(num, st->fl, 0);
	return (count);
}

static int	print_ptr(unsigned long num, int len, int count, t_parse *st)
{
	if (st->negative && st->wi)
	{
		(st->dot) ? count += print_void('0', st->pr - len) : 0;
		count += write(1, "0x", 2);
		ft_puthex(num, st->fl, 0);
		count += print_void(' ', st->wi - ((st->pr > len) ? st->pr : len));
	}
	else if (st->zero && st->wi && !st->dot)
	{
		count += print_void('0', st->wi - len);
		count += write(1, "0x", 2);
		ft_puthex(num, st->fl, 0);
	}
	else if ((st->wi && !st->dot) || (st->wi && st->dot) || st->dot)
		count += print_ptr2(num, len, count, st);
	else
	{
		count += write(1, "0x", 2);
		ft_puthex(num, st->fl, 0);
	}
	return (count);
}

int			print_pointer(va_list args, t_parse *st)
{
	void	*ptr;
	int		len;

	ptr = va_arg(args, void*);
	len = count_len((unsigned long)ptr);
	if (!ptr && st->dot && !st->pr)
	{
		st->fl = 1;
		len -= 1;
	}
	(st->wi) ? (st->wi -= 2) : 0;
	len += print_ptr((unsigned long)ptr, len, 0, st);
	return (len);
}

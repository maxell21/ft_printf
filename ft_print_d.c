/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:37:04 by maxell            #+#    #+#             */
/*   Updated: 2020/12/26 21:19:04 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num(int num, int len, t_parse st)
{
	int count;

	count = 0;
	(st.dot) ? (st.zero = 0) : 0;
	(st.negative) ? (st.zero = 0) : 0;
	if (st.negative && st.width)
	{
		(st.is_neg) ? ft_putchar('-') : 0;
		(st.dot) ? count += print_void('0', st.precision - len) : 0;
		ft_putnbr_fd(ft_abs(num), 1);
		count += print_void(' ', st.width - ((st.precision > len) ? st.precision : len));
	}
	else if (st.zero && st.width && !st.dot)
	{
		(st.is_neg) ? ft_putchar('-') : 0;
		count += print_void('0', st.width - len);
		ft_putnbr_fd(num, 1);
	}
	else if (st.width && !st.dot)
	{
		count += print_void(' ', st.width - len);
		(st.is_neg) ? ft_putchar('-') : 0;
		ft_putnbr_fd(num, 1);
	}
	else if (st.width && st.dot)
	{
		count += print_void(' ', st.width - ((st.precision > len) ? st.precision : len));
		(st.is_neg) ? ft_putchar('-') : 0;
		count += print_void('0', (st.precision > len) ? st.precision - len : 0);
		ft_putnbr_fd(num, 1);
	}
	else if (st.dot)
	{
		(st.is_neg) ? ft_putchar('-') : 0;
		(st.is_neg) ? len-- : 0;
		count += print_void('0', st.precision - len);
		ft_putnbr_fd(num, 1);
	}
	else
	{
		(st.is_neg) ? ft_putchar('-') : 0;
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
	len += print_num(num, len, *st);
	return (len);
}

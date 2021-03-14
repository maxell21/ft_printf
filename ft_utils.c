/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:17:59 by maxell            #+#    #+#             */
/*   Updated: 2021/01/09 21:41:26 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_puthex(unsigned long n, int fl, int fl2)
{
	if (fl == 1)
		return ;
	if (n > 15)
	{
		ft_puthex((n / 16), fl, fl2);
		ft_puthex((n % 16), fl, fl2);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
	{
		if (n == 10)
			(fl2) ? ft_putchar('A') : ft_putchar('a');
		if (n == 11)
			(fl2) ? ft_putchar('B') : ft_putchar('b');
		if (n == 12)
			(fl2) ? ft_putchar('C') : ft_putchar('c');
		if (n == 13)
			(fl2) ? ft_putchar('D') : ft_putchar('d');
		if (n == 14)
			(fl2) ? ft_putchar('E') : ft_putchar('e');
		if (n == 15)
			(fl2) ? ft_putchar('F') : ft_putchar('f');
	}
}

int			print_void(char c, int width)
{
	int i;

	i = 0;
	if (width > 0)
		while (width--)
		{
			write(1, &c, 1);
			i++;
		}
	return (i);
}

void		ft_putstr_width(char *s, int width)
{
	int i;

	i = 0;
	while (s[i] && i < width)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int			skip_flags(char *str, int i, t_parse *arg)
{
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '0')
			arg->zero = 1;
		if (str[i] == '-')
			arg->negative = 1;
		i++;
	}
	return (i);
}

int			ft_num_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		len += 1;
		num = num / 10;
	}
	return (len);
}

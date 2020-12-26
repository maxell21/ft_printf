/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:17:59 by maxell            #+#    #+#             */
/*   Updated: 2020/12/26 21:18:36 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_void(char c, int width)
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

void	ft_putstr_width(char *s, int width)
{
	int i;

	i = 0;
	while (s[i] && i < width)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		skip_flags(char *str, int i, t_parse *arg)
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

int		ft_abs(int num)
{
	if (num <= 0)
		return (num * (-1));
	return (num);
}

int		ft_num_len(int num)
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

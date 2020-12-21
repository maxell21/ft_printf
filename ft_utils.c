/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:17:59 by maxell            #+#    #+#             */
/*   Updated: 2020/12/21 19:45:32 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_void(char c, int width)
{
	while (width--)
		write(1, &c, 1);
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int		ft_num_len(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len += 1;
		num = num / 10;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:47:19 by maxell            #+#    #+#             */
/*   Updated: 2020/11/03 17:44:27 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_len(long int nb)
{
	int		count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static char	*ft_fill_array(long int nb, int len, char *memory)
{
	int flag;

	flag = 0;
	if (nb < 0)
	{
		flag++;
		nb *= -1;
	}
	memory[len] = '\0';
	while (--len)
	{
		memory[len] = (nb % 10) + 48;
		nb /= 10;
	}
	if (flag != 0)
		memory[0] = 45;
	else
		memory[0] = (nb % 10) + 48;
	return (memory);
}

char		*ft_itoa(int n)
{
	int			len;
	long int	num;
	char		*memory;

	num = (long int)n;
	len = ft_count_len(num);
	memory = (char*)malloc(sizeof(char) * (len + 1));
	if (!memory)
		return (0);
	memory = ft_fill_array(num, len, memory);
	return (memory);
}

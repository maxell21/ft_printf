/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:37:04 by maxell            #+#    #+#             */
/*   Updated: 2020/12/23 20:28:28 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pr_wi(int num, int pr, int wi, int fl)
{
	int	len;
	int res;

	len = ft_num_len(num);
	res = 0;
	if (wi > pr && fl != 1 && wi > len)
		print_void(' ', wi - pr - 1);
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		res = 1;
	}
	ft_putnbr_fd(num, 1);
	if (wi > len && pr > len && wi > pr && fl == 1)
		print_void('0', pr - (res == 0 ? len : len + 1));
	// if ( && fl == 1 && wi > len)
	// 	print_void(' ', wi - pr - len - 1);
	// if (wi > len)
	// {
	// 	len = len + wi;
	// }
	return (len);
}

static int	print_pos(int num, t_parse st)
{
	int	width;
	int	len;

	len = ft_num_len(num);
	width = st.width;
	if (st.precision != 0 || (st.precision != 0 && st.width != 0))
		return (print_pr_wi(num, st.precision, st.width, st.negative));
	if ((st.negative == 0 && width != 0) && width > len)
		print_void((st.zero == 1 ? '0' : ' '), width - len);
	ft_putnbr_fd(num, 1);
	if ((st.negative == 1 && width != 0) && width > len)
		print_void((st.zero == 1 ? '0' : ' '), width - len);
	return (width > len ? width : len);
}

static int	print_neg(int num, t_parse st)
{
	int	width;
	int	len;

	len = ft_num_len(num);
	width = st.width;
	if (st.zero == 1)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (st.precision != 0 || (st.precision != 0 && st.width != 0))
		return (print_pr_wi(num, st.precision, st.width, st.negative));
	else
		return (print_pos(num, st));
}

// static int	print_pos(int num, t_parse st)
// {
// 	st.width = 7;
// 	ft_putnbr_fd(num, 1);
// 	return (ft_num_len(num));
// }

// static int	print_neg(int num, t_parse st)
// {
// 	st.width = 7;
// 	ft_putnbr_fd(num, 1);
// 	return (ft_num_len(num));
// }

int			print_digit(va_list args, t_parse *st)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	if (!num)
		num = 0;
	if (num <= 0)
		len = print_neg(num, *st);
	else
		len = print_pos(num, *st);
	return (len);
}

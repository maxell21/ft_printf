/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:26:25 by maxell            #+#    #+#             */
/*   Updated: 2020/12/21 19:07:30 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list arg, t_parse *ag_str)
{
	int		wi;
	char	c;

	c = va_arg(arg, int);
	wi = ag_str->width;
	if (wi != 0 && ag_str->negative == 0)
		print_void(' ', wi - 1);
	write(1, &c, 1);
	if (wi != 0 && ag_str->negative == 1)
		print_void(' ', wi - 1);
	return (wi == 0 ? 1 : wi);
}

int			print_str(va_list args, t_parse *ag_str)
{
	int		wi;
	int		pr;
	int		len;
	char	*s;

	s = va_arg(args, char*);
	wi = ag_str->width;
	len = ft_strlen(s);
	if (ag_str->precision == 0)
		pr = len;
	else
		pr = (ag_str->precision < len ? ag_str->precision : len);
	if (wi > pr && ag_str->negative == 0)
		print_void(' ', wi - pr);
	ft_putstr_width(s, pr);
	if (wi > pr && ag_str->negative == 1)
		print_void(' ', wi - pr);
	return (wi > pr ? wi : pr);
}
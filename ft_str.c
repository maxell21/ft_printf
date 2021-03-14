/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:26:25 by maxell            #+#    #+#             */
/*   Updated: 2021/01/11 21:02:22 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(va_list arg, t_parse *ag_str)
{
	char	c;

	c = va_arg(arg, int);
	if (ag_str->wi != 0 && ag_str->negative == 0)
		print_void(' ', ag_str->wi - 1);
	write(1, &c, 1);
	if (ag_str->wi != 0 && ag_str->negative == 1)
		print_void(' ', ag_str->wi - 1);
	return (ag_str->wi == 0 ? 1 : ag_str->wi);
}

int			print_str(va_list args, t_parse *ag_str)
{
	int		len;
	char	*s;

	s = va_arg(args, char*);
	(ag_str->zero && (ag_str->negative || ag_str->dot)) ? ag_str->zero = 0 : 0;
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (ag_str->dot && !ag_str->pr)
		ag_str->pr = 0;
	else if (!ag_str->dot && !ag_str->pr)
		ag_str->pr = len;
	else if (ag_str->pr && ag_str->neg_star)
		ag_str->pr = len;
	else
		ag_str->pr = (ag_str->pr < len ? ag_str->pr : len);
	if (ag_str->wi > ag_str->pr && !ag_str->negative)
		print_void((ag_str->zero ? '0' : ' '), ag_str->wi - ag_str->pr);
	ft_putstr_width(s, ag_str->pr);
	if (ag_str->wi > ag_str->pr && ag_str->negative)
		print_void((ag_str->zero ? '0' : ' '), ag_str->wi - ag_str->pr);
	return (ag_str->wi > ag_str->pr ? ag_str->wi : ag_str->pr);
}

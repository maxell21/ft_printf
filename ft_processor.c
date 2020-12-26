/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:49:39 by maxell            #+#    #+#             */
/*   Updated: 2020/12/21 20:35:21 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_percent(va_list arg, t_parse *ag_str)
{
	int		wi;
	char	c;

	c = va_arg(arg, int);
	wi = ag_str->width;
	if (wi != 0 && ag_str->negative == 0 && !ag_str->zero)
		print_void((ag_str->zero == 1 ? '0' : ' '), wi - 1);
	write(1, "%", 1);
	if (wi != 0 && ag_str->negative == 1)
		print_void((ag_str->zero == 1 ? '0' : ' '), wi - 1);
	return (wi == 0 ? 1 : wi);
}

int				process_arg(va_list args, t_parse *ag_str)
{
	char	type;

	type = ag_str->type;
	if (type == 'c')
		ag_str->length = print_char(args, ag_str);
	if (type == 's')
		ag_str->length = print_str(args, ag_str);
	if (type == 'p')
		ag_str->length = print_pointer(args, ag_str);
	if (type == 'd')
		ag_str->length = print_digit(args, ag_str);
	if (type == 'i')
		ag_str->length = 1;
	if (type == 'u')
		ag_str->length = 1;
	if (type == 'x')
		ag_str->length = 1;
	if (type == 'X')
		ag_str->length = 1;
	if (type == '%')
		ag_str->length = print_percent(args, ag_str);
	return (ag_str->length);
}

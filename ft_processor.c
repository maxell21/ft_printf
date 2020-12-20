/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:22:29 by maxell            #+#    #+#             */
/*   Updated: 2020/12/11 20:35:44 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_percent()
{
	write(1, "%", 1);
	return (1);
}

int		process_arg(va_list args, t_parse *ag_str)
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
		ag_str->length = 1;
	if (type == 'i')
		ag_str->length = 1;
	if (type == 'u')
		ag_str->length = 1;
	if (type == 'x')
		ag_str->length = 1;
	if (type == 'X')
		ag_str->length = 1;
	if (type == '%')
		ag_str->length = print_percent();
	return (ag_str->length);
}

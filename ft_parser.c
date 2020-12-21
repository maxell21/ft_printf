/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:47:20 by maxell            #+#    #+#             */
/*   Updated: 2020/12/21 19:47:26 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_parse	*initialize(t_parse *args)
{
	args->zero = 0;
	args->negative = 0;
	args->width = 0;
	args->precision = 0;
	args->length = 0;
	args->type = '0';
	args->dot = 0;
	return (args);
}

static int		count_precision(char *str, int i, t_parse *ag_str)
{
	int	pr;

	pr = 0;
	i = i + 1;
	if (str[i] == '*')
		pr = 1;
	while (ft_isdigit(str[i]))
	{
		pr = (pr * 10) + (str[i] - 48);
		i++;
	}
	ag_str->dot = 1;
	ag_str->precision = pr;
	return (i);
}

static int		parser(char *str, int i, va_list args, t_parse *st)
{
	int	wi;

	wi = 0;
	i = skip_flags(str, i, st);
	while (!ft_istype(str[i]) && st->dot == 0)
	{
		if (ft_isdigit(str[i]))
			wi = (wi * 10) + (str[i] - 48);
		if (str[i] == '.')
			i = count_precision(str, i, st) - 1;
		i++;
	}
	st->width = wi;
	st->type = str[i];
	(st->zero && (st->negative || st->dot)) ? st->zero = 0 : 0;
	process_arg(args, st);
	return (i + 1);
}

int				print_args(const char *str, va_list args)
{
	int		i;
	int		result_len;
	t_parse	arg_struct;

	i = 0;
	result_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			initialize(&arg_struct);
			i = parser((char*)str, i + 1, args, &arg_struct) - 1;
			result_len += arg_struct.length;
		}
		else
			result_len += write(1, &str[i], 1);
		i++;
	}
	return (result_len);
}

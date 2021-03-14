/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:47:20 by maxell            #+#    #+#             */
/*   Updated: 2021/01/13 17:48:28 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_parse	*initialize(t_parse *args)
{
	args->zero = 0;
	args->negative = 0;
	args->wi = 0;
	args->pr = 0;
	args->length = 0;
	args->type = '0';
	args->dot = 0;
	args->is_neg = 0;
	args->fl = 0;
	args->large_x = 0;
	args->star = 0;
	args->neg_star = 0;
	return (args);
}

static int		count_precision(char *str, int i, t_parse *ag_str, va_list args)
{
	int	pr;
	int n;

	pr = 0;
	i = i + 1;
	if (str[i] == '*')
	{
		n = va_arg(args, int);
		pr = n;
		i++;
		ag_str->star = 1;
	}
	while (ft_isdigit(str[i]))
	{
		pr = (pr * 10) + (str[i] - 48);
		i++;
	}
	ag_str->dot = 1;
	ag_str->pr = pr;
	return (i);
}

static int		parser(char *str, int i, va_list args, t_parse *st)
{
	int	wi;
	int num;

	wi = 0;
	i = skip_flags(str, i, st);
	while (!ft_istype(str[i]) && st->dot == 0)
	{
		if (ft_isdigit(str[i]))
			wi = (wi * 10) + (str[i] - 48);
		if (str[i] == '*')
		{
			num = va_arg(args, int);
			wi = num;
			st->star = 1;
		}
		if (str[i] == '.')
			i = count_precision(str, i, st, args) - 1;
		i++;
	}
	st->wi = wi;
	st->type = str[i];
	process_arg(args, st);
	return (i);
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
			i++;
			initialize(&arg_struct);
			i = parser((char*)str, i, args, &arg_struct);
			result_len += arg_struct.length;
		}
		else
			result_len += write(1, &str[i], 1);
		i++;
	}
	return (result_len);
}

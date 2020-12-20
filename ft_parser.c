/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:26:25 by maxell            #+#    #+#             */
/*   Updated: 2020/12/17 17:49:40 by maxell           ###   ########.fr       */
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

static int		parser(char *str, int i, va_list args, t_parse *ag_str)
{
	int	wi;

	wi = 0;
	i = skip_flags(str, i, ag_str);
	while (!ft_istype(str[i]) && ag_str->dot == 0)
	{
		if (ft_isdigit(str[i]))
			wi = (wi * 10) + (str[i] - 48);
		if (str[i] == '.')
			i = count_precision(str, i, ag_str);
		i++;
	}
	ag_str->width = wi;
	ag_str->type = str[i];
	process_arg(args, ag_str);
	return (i + 1);
}

int		print_args(const char *str, va_list args)
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
			i = parser((char*)str, i + 1, args, &arg_struct);
			result_len += arg_struct.length;
		}
		write(1, &str[i], 1);
		i++;
		result_len++;
	}
	return (result_len);
}
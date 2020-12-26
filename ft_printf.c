/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxell <maxell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:48:36 by maxell            #+#    #+#             */
/*   Updated: 2020/12/23 20:08:03 by maxell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;

	va_start(args, str);
	len = print_args(str, args);
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:42:34 by blacking          #+#    #+#             */
/*   Updated: 2019/11/06 13:27:15 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list params;
	int count;

	va_start(params, str);
	count = 0;
	while(*str)
	{
		if(*str == '%')
			ft_fill_struct(&str, &count, params);
		else
		{
			write(1, str, 1);
			count += 1;
		}
		str++;
	}
	va_end(params);
	return (count);
}

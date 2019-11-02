/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:42:34 by blacking          #+#    #+#             */
/*   Updated: 2019/11/02 13:27:51 by blacking         ###   ########.fr       */
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
		if(parse(str, params) == 1)
		{
			str++;
		}
		count++;
		str++;
	}
	va_end(params);
	return (count);
}

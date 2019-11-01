/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:42:34 by blacking          #+#    #+#             */
/*   Updated: 2019/11/01 16:49:03 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		ft_printf(const char *str, ...)
{
	int count;

	count = 0;
	while(*str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}

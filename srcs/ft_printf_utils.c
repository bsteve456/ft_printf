/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:14:20 by blacking          #+#    #+#             */
/*   Updated: 2019/11/14 16:18:42 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int		count_numbers(long number, int base, t_printf *params)
{
	int count;

	count = (number < 0) ? 1 : 0;
	if (number == 0 && params->prec == 0 && params->dot_num > 0 && params->dot == 1)
		return (0);
	else if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= base;
		count++;
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s == 0)
		return (0);
	while (s[count])
		count++;
	return (count);
}

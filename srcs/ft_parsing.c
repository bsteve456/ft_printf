/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:49:37 by blacking          #+#    #+#             */
/*   Updated: 2019/11/02 14:39:51 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int parse(const char *str, va_list params, int *count)
{
	if(ft_strncmp(str, "%d", 2) == 0)
	{
		ft_putnbr(va_arg(params, int), count);
		return (1);
	}
	write(1, str, 1);
	*count += 1;
	return (0);
}

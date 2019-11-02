/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:49:37 by blacking          #+#    #+#             */
/*   Updated: 2019/11/02 13:19:15 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int parse(const char *str, va_list params)
{
	if(ft_strncmp(str, "%d", 2) == 0)
	{
		ft_putnbr(va_arg(params, int));
		return (1);
	}
	write(1, str, 1);
	return (0);
}

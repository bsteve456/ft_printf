/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:49:37 by blacking          #+#    #+#             */
/*   Updated: 2019/11/05 15:51:53 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int parse(const char *str, va_list params, int *count)
{
	if(ft_strncmp(str, "%d", 2) == 0 ||
	ft_strncmp(str, "%i", 2) == 0 || ft_strncmp(str, "%u", 2) == 0)
		ft_putnbr(va_arg(params, int), count);
	else if(ft_strncmp(str, "%c", 2) == 0)
		ft_putchar_int(va_arg(params, int), count);
	else if(ft_strncmp(str, "%s", 2) == 0)
		ft_putstr(va_arg(params, char *), count);
	else if(ft_strncmp(str, "%p", 2) == 0)
		ft_putnbr_hexa(va_arg(params, char *), count, str);
	else if(ft_strncmp(str, "%x", 2) == 0 ||
	ft_strncmp(str, "%X", 2) == 0)
		ft_putnbr_hexa2(va_arg(params, int), count, str);
	else if(ft_strncmp(str, "%%", 2) == 0)
		ft_putchar_int('%', count);
	else
		return (0);
	return (1);
}

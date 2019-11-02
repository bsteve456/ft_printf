/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:49:37 by blacking          #+#    #+#             */
/*   Updated: 2019/11/02 16:15:46 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int parse(const char *str, va_list params, int *count)
{
	if(ft_strncmp(str, "%d", 2) == 0 ||
	ft_strncmp(str, "%i", 2) == 0)
		ft_putnbr(va_arg(params, int), count);
	else if(ft_strncmp(str, "%c", 2) == 0)
		ft_putchar(va_arg(params, char));
	else if(ft_strncmp(str, "%s", 2) == 0)
		ft_putstr(va_arg(params, char *));
	else if(ft_strncmp(str, "%p", 2) == 0)
	
	else if(ft_strncmp(str, "%x", 2) == 0 ||
	ft_strncmp(str, "%X", 2) == 0)
		
	else if(ft_strncmp(str, "%%", 2) == 0)

	else
		return (0);
	return (1);
}

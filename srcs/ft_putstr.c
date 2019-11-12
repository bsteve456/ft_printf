/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:43:59 by blacking          #+#    #+#             */
/*   Updated: 2019/11/12 16:39:09 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putchar_int(unsigned char c, int *p)
{
	write(1, &c, 1);
	*p += 1;
}

void	ft_putstr(char *str, int *p)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
		*p += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:04:31 by blacking          #+#    #+#             */
/*   Updated: 2019/11/06 16:07:25 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	width_precision(t_printf *params, int *count)
{
	int i;

	i = 0;
	while(i < (params->width - count_numbers(params->var_int)))
	{
		ft_putchar(' ');
		i++;
		*count += 1;
	}
}

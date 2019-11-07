/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:04:31 by blacking          #+#    #+#             */
/*   Updated: 2019/11/07 16:26:48 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
void	width_precision(t_printf *params, int *count)
{
	int i;
	int size;

	i = 0;
	size = (params->type == 'p') ?
	count_numbers(params->var_unslong, 16) + 2
	: count_numbers(params->var_int, 10);
	while(i < (params->width - size))
	{
		ft_putchar(' ');
		i++;
		*count += 1;
	}
}

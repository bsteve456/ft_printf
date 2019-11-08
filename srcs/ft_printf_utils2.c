/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:04:31 by blacking          #+#    #+#             */
/*   Updated: 2019/11/08 14:57:43 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
void	width_precision(t_printf *params, int *count)
{
	int i;
	int size;

	i = 0;
	if(params->type == 'c')
		size = 1;
	else if (params->type == 'p')
		size = count_numbers(params->var_unslong, 16) + 2;
	else if(params->type == 'x' || params->type == 'X')
		size = count_numbers(params->var_unsint, 10);
	else if(params->type == 's')
		size = ft_strlen(params->var_string);
	else
		size = count_numbers(params->var_int, 10);
	while(i < (params->width - size))
	{
		ft_putchar(' ');
		i++;
		*count += 1;
	}
}

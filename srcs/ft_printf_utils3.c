/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:59:43 by stbaleba          #+#    #+#             */
/*   Updated: 2019/11/15 14:29:41 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			width_part2(t_printf *params, int size)
{
	if (params->type == 's' && params->dot == 1 && params->prec <= size)
		size = params->prec;
	if (verif_dot(params) == 0)
		size = 0;
	else if (params->type != 's')
		size = (params->prec > size) ? params->prec : size;
	if (params->var_int < 0 && params->dot == 1 && params->prec >= size)
		size += 1;
	return (size);
}

int			width_zero_neg(t_printf *params, int width_prec, int *count)
{
	ft_putchar_int('-', count);
	params->var_int = -(params->var_int);
	if (params->dot == 1)
		width_prec += 1;
	if (params->minus == 1)
		params->width -= 1;
	return (width_prec);
}

void		check_dot_prec(t_printf *params)
{
	if (params->dot == 1 && params->prec == 0 && params->dot_num == 0)
		params->prec += 1;
	if (params->dot == 1 && params->prec < 0)
	{
		params->dot = 0;
		params->prec = 0;
	}
}

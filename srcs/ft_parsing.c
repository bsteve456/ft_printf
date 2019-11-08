/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:49:37 by blacking          #+#    #+#             */
/*   Updated: 2019/11/08 14:43:40 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	parse(t_printf *params, int *count)
{
	if(params->type == 'd' || params->type == 'i'
	|| params->type == 'u')
		ft_putnbr(params->var_int, count);
	else if(params->type == 'c')
		ft_putchar_int(params->var_int, count);
	else if(params->type == 's')
		ft_putstr(params->var_string, count);
	else if(params->type == 'p')
		ft_putnbr_hexa(params->var_unslong, count, params);
	else if(params->type == 'x' || params->type == 'X')
		ft_putnbr_hexa(params->var_unsint, count, params);
	else if(params->type == '%')
		ft_putchar_int('%', count);
}

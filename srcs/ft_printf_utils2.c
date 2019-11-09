/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:04:31 by blacking          #+#    #+#             */
/*   Updated: 2019/11/09 15:15:45 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	width(t_printf *params, int *count)
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
		ft_putchar_int(' ', count);
		i++;
	}
}

void	width_zero(t_printf *params, int *count)
{
	int i;
	int size;

	i = 0;
	if (params->type == 'p')
		size = count_numbers(params->var_unslong, 16) + 2;
	else if(params->type == 'x' || params->type == 'X')
		size = count_numbers(params->var_unsint, 10);
	else
		size = count_numbers(params->var_int, 10);
	if(params->var_int < 0)
	{
		ft_putchar_int('-', count);
		params->var_int = -(params->var_int);
	}
	while(i < (params->width - size))
	{
		ft_putchar_int('0', count);
		i++;
	}
}

void	fill_width_precision(const char **str, t_printf *params)
{
	(*str)++;
	if (**str == '0')
		params->zero = 1;
	while(ft_isalpha(**str) == 0 && **str != '%')
	{
		if(**str == '-')
			params->minus = 1;
		if(ft_isdigit(**str) == 2048)
			params->width = (params->width * 10) + (**str - '0');
		(*str)++;
	}
	params->type = **str;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:04:31 by blacking          #+#    #+#             */
/*   Updated: 2019/11/12 16:50:19 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	width(t_printf *params, int *count)
{
	int i;
	int size;

	i = 0;
	if (params->type == 'c')
		size = 1;
	else if (params->type == 'p')
		size = count_numbers(params->var_unslong, 16) + 2;
	else if (params->type == 'x' || params->type == 'X')
		size = count_numbers(params->var_unsint, 16);
	else if (params->type == 's')
		size = ft_strlen(params->var_string);
	else
		size = count_numbers(params->var_int, 10);
	size = (params->prec > size) ? params->prec : size;
	while (i < (params->width - size))
	{
		ft_putchar_int(' ', count);
		i++;
	}
}

void	width_zero(t_printf *params, int *count)
{
	int i;
	int size;
	int width_prec;

	i = 0;
	width_prec = (params->dot == 1) ? params->prec : params->width;
	if (params->type == 'p')
		size = count_numbers(params->var_unslong, 16) + 2;
	else if (params->type == 'x' || params->type == 'X')
		size = count_numbers(params->var_unsint, 16);
	else
		size = count_numbers(params->var_int, 10);
	if (params->var_int < 0)
	{
		ft_putchar_int('-', count);
		params->var_int = -(params->var_int);
		if (params->dot == 1)
			width_prec += 1;
	}
	while (i < (width_prec - size))
	{
		ft_putchar_int('0', count);
		i++;
	}
}

void	fill_width_prec(const char **str, t_printf *params, va_list ap)
{
	(*str)++;
	if (**str == '0')
		params->zero = 1;
	while (ft_isalpha(**str) == 0 && **str != '%')
	{
		if (**str == '-')
			params->minus = 1;
		if (**str == '.')
			params->dot = 1;
		if (**str == '*' && params->dot == 0)
			params->width = va_arg(ap, int);
		else if (**str == '*' && params->dot == 1)
			params->prec = va_arg(ap, int);
		if (ft_isdigit(**str) == 2048 && params->dot == 0)
			params->width = (params->width * 10) + (**str - '0');
		else if (ft_isdigit(**str) == 2048 && params->dot == 1)
			params->prec = (params->prec * 10) + (**str - '0');
		(*str)++;
	}
	if (params->dot == 1 && params->prec == 0)
		params->prec += 1;
	params->type = **str;
}

void	precision(t_printf *params, int *count)
{
	int		i;
	char	*str;

	i = 0;
	str = params->var_string;
	while (str[i] && i < params->prec)
	{
		ft_putchar(str[i]);
		*count += 1;
		i++;
	}
}

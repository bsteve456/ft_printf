/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:21:28 by blacking          #+#    #+#             */
/*   Updated: 2019/11/09 15:10:36 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_printf	*init_struct(void)
{
	t_printf *new;

	new = NULL;
	if(!(new = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	new->width = 0;
	new->minus = 0;
	new->zero = 0;
	return (new);
}

void	ft_parsing_flags(t_printf *params, int *count)
{
	if(params->type != '%' && params->minus == 0 && params->zero == 0)
		width(params, count);
	else if(params->zero == 1 &&
	params->type != '%' && params->type != 's' &&
	params->type != 'c')
		width_zero(params, count);
	if(params->type == 'p' && write(1, "0x", 2))
		*count += 2;
	parse(params, count);
	if(params->minus == 1)
		width(params, count);
	free(params);
}

void	ft_fill_struct(const char **str, int *count, va_list ap)
{
	t_printf *params;

	params = init_struct();
	fill_width_precision(str, params);
	if (params->type == 'p')
		ft_putaddr(params, count, ap);
	else if(params->type == 's')
		params->var_string = va_arg(ap, char *);
	else if(params->type == 'x' || params->type == 'X')
		params->var_unsint = va_arg(ap, int);
	else if(params->type != '%')
		params->var_int = va_arg(ap, int);
	ft_parsing_flags(params, count);
}

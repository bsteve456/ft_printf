/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:21:28 by blacking          #+#    #+#             */
/*   Updated: 2019/11/15 13:49:23 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_printf	*init_struct(void)
{
	t_printf *new;

	new = NULL;
	if (!(new = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	new->width = 0;
	new->minus = 0;
	new->zero = 0;
	new->dot = 0;
	new->prec = 0;
	new->dot_num = 0;
	new->var_int = 0;
	return (new);
}

void		ft_parsing_flags(t_printf *params, int *count)
{
	if ((params->minus == 0 && params->zero == 0) ||
		(params->zero == 1 && params->type == 's') ||
		(params->zero == 1 && params->dot == 1 && params->minus == 0))
		width(params, count);
	else if (params->zero == 1 && params->minus == 0 &&
	params->type != 's' && params->type != 'c' && params->dot == 0)
		width_zero(params, count);
	if (params->dot == 1 && params->type == 's')
		precision(params, count);
	else if (params->dot == 1 && params->type != '%' &&
	params->type != 'c')
		width_zero(params, count);
	if (params->type == 'p')
		write(1, "0x", 2);
	if (verif_dot(params) == 1)
		parse(params, count);
	if (params->minus == 1)
		width(params, count);
	free(params);
}

void		parse(t_printf *params, int *count)
{
	if (params->type == 'd' || params->type == 'i')
		ft_putnbr(params->var_int, count);
	else if (params->type == 'u')
		ft_putnbr(params->var_unsint, count);
	else if (params->type == 'c')
		ft_putchar_int(params->var_int, count);
	else if (params->type == 's' && params->dot == 0)
		ft_putstr(params->var_string, count);
	else if (params->type == 'p')
		ft_putnbr_hexa(params->var_unslong, count, params);
	else if (params->type == 'x' || params->type == 'X')
		ft_putnbr_hexa(params->var_unsint, count, params);
	else if (params->type == '%')
		ft_putchar_int('%', count);
}

void		ft_fill_struct(const char **str, int *count, va_list ap)
{
	t_printf *params;

	params = init_struct();
	fill_width_prec(str, params, ap);
	if (params->width < 0)
	{
		params->minus = 1;
		params->width = -(params->width);
	}
	if (params->type == 'p')
		ft_putaddr(params, count, ap);
	else if (params->type == 's')
		params->var_string = va_arg(ap, char *);
	else if (params->type == 'x' || params->type == 'X' || params->type == 'u')
		params->var_unsint = va_arg(ap, int);
	else if (params->type != '%')
		params->var_int = va_arg(ap, int);
	if (params->type == 's' && params->var_string == NULL)
		params->var_string = "(null)";
	ft_parsing_flags(params, count);
}

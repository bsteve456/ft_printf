/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:21:28 by blacking          #+#    #+#             */
/*   Updated: 2019/11/07 16:24:21 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_printf	*init_struct(void)
{
	t_printf *new;

	new = NULL;
	if(!(new = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	new->type = 0;
	new->width = 0;
	new->var_int = 0;
	new->var_string = NULL;
	new->var_unslong = 0;
	return (new);
}

void	ft_parsing_flags(t_printf *params, int *count)
{
	width_precision(params, count);
	if(params->type == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
	}
	parse(params, count);
	free(params);
}

void	ft_fill_struct(const char **str, int *count, va_list ap)
{
	t_printf *params;

	params = init_struct();
	while(ft_isalpha(**str) == 0)
	{
		if(ft_isdigit(**str) == 2048)
			params->width = (params->width * 10) + (**str - '0');
		(*str)++;
	}
	params->type = **str;
	if (params->type == 'p')
		ft_putaddr(params, count, ap);
	else
		params->var_int = va_arg(ap, int);
	ft_parsing_flags(params, count);
}

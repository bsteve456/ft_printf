/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:21:28 by blacking          #+#    #+#             */
/*   Updated: 2019/11/06 12:28:00 by blacking         ###   ########.fr       */
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
	return (new);
}

void	ft_fill_struct(const char **str, int *count, va_list ap)
{
	t_printf *params;

	params = init_struct();
	while(ft_isalpha(**str) != 0)
	{
		while (ft_isdigit(**str) == 2048)
		{
			params->width *= 10 + (**str - '0');
			*str++;
		}
		*str++;
	}
	params->var_int = va_arg(ap, int);
	params->type = **str;
	ft_parsing2(params, count);
}

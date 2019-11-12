/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:43:31 by stbaleba          #+#    #+#             */
/*   Updated: 2019/11/12 16:39:45 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr, int *p)
{
	unsigned int nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		*p += 1;
	}
	nb = (nbr < 0) ? -nbr : nbr;
	if (nb >= 10)
		ft_putnbr((nb / 10), p);
	*p += 1;
	ft_putchar((nb % 10) + '0');
}

void	ft_putnbr_hexa(long nbr, int *p, t_printf *params)
{
	char			*hexa;
	unsigned long	nb;

	if (params->type == 'x' || params->type == 'p')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	nb = nbr;
	if (nb >= 16)
		ft_putnbr_hexa((nb / 16), p, params);
	*p += 1;
	ft_putchar(hexa[nb % 16]);
}

void	ft_putaddr(t_printf *params, int *p, va_list ap)
{
	unsigned long nb;

	*p += 2;
	params->var_string = va_arg(ap, char *);
	nb = (unsigned long)(params->var_string);
	params->var_unslong = nb;
}

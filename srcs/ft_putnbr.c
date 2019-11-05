/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:43:31 by stbaleba          #+#    #+#             */
/*   Updated: 2019/11/05 16:00:36 by blacking         ###   ########.fr       */
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

void	ft_putnbr_hexa(long nbr, int *p, const char *str)
{
	char *hexa;
	unsigned long nb;

	if(ft_strncmp(str, "%x", 2) == 0 || ft_strncmp(str, "%p", 2) == 0)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if(ft_strncmp(str, "%p", 2) == 0)
		nb = nbr;
	else
		nb = (unsigned int)nbr;
	if (nb >= 16)
		ft_putnbr_hexa((nb / 16), p, str);
	*p += 1;
	ft_putchar(hexa[nb % 16]);
}

void	ft_putaddr(char *nbr, int *p, const char *str)
{
	unsigned long nb;

	*p += 2;
	write(1, "0x", 2);
	nb = (unsigned long)(nbr);
	ft_putnbr_hexa(nb, p, str);
}

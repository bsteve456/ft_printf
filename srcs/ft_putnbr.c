/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:43:31 by stbaleba          #+#    #+#             */
/*   Updated: 2019/11/02 14:37:59 by blacking         ###   ########.fr       */
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
		nb = nbr * (-1);
	}
	else
		nb = nbr;
	if (nb >= 10)
		ft_putnbr((nb / 10), p);
	*p += 1;
	ft_putchar((nb % 10) + '0');
}

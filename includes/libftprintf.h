/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:34:39 by blacking          #+#    #+#             */
/*   Updated: 2019/11/02 14:38:57 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *, ...);
int		parse(const char *str, va_list params, int *count);
void	ft_putchar(char c);
void	ft_putnbr(int nbr, int *p);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

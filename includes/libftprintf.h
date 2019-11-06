/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:34:39 by blacking          #+#    #+#             */
/*   Updated: 2019/11/06 13:31:21 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_printf
{
	char	type;
	int		width;
	int		var_int;
}				t_printf;
int		ft_printf(const char *, ...);
void		parse(t_printf *params, int *count);
void	ft_putchar(char c);
void	ft_putnbr(int nbr, int *p);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str, int *p);
void	ft_putchar_int(unsigned char c, int *p);
void	ft_putaddr(char *nbr, int *p, const char *str);
void	ft_putnbr_hexa(long nbr, int *p, const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		count_numbers(int number);
size_t	ft_strlen(const char *s);
void	ft_fill_struct(const char **str, int *count, va_list ap);
#endif

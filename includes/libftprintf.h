/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:34:39 by blacking          #+#    #+#             */
/*   Updated: 2019/11/15 14:29:33 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_printf
{
	char			type;
	int				width;
	int				var_int;
	char			*var_string;
	unsigned long	var_unslong;
	unsigned int	var_unsint;
	int				minus;
	int				zero;
	int				dot;
	int				prec;
	int				dot_num;
}				t_printf;
void			parse(t_printf *params, int *count);
void			ft_putchar(char c);
void			ft_putnbr(long nbr, int *p);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr(char *str, int *p);
void			ft_putchar_int(unsigned char c, int *p);
void			ft_putaddr(t_printf *params, int *p, va_list ap);
void			ft_putnbr_hexa(long nbr, int *p, t_printf *params);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				count_numbers(long number, int base, t_printf *params);
size_t			ft_strlen(const char *s);
void			ft_fill_struct(const char **str, int *count, va_list ap);
void			width(t_printf *params, int *count);
void			fill_width_prec(const char **str, t_printf *params, va_list ap);
void			width_zero(t_printf *params, int *count);
void			precision(t_printf *params, int *count);
int				verif_dot(t_printf *params);
int				width_part2(t_printf *params, int size);
int				width_zero_neg(t_printf *params, int width_prec, int *count);
void			check_dot_prec(t_printf *params);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:08:35 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:08:37 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_id(va_list *ap, t_param *p)
{
	if (p->lenght == hh)
		return (ft_put_int((char)va_arg(*ap, int), p));
	else if (p->lenght == h)
		return (ft_put_int((short)va_arg(*ap, int), p));
	else if (p->lenght == ll)
		return (ft_put_int((long long)va_arg(*ap, long long), p));
	else if (p->lenght == l)
		return (ft_put_int((long)va_arg(*ap, long), p));
	else if (p->lenght == j)
		return (ft_put_int((intmax_t)va_arg(*ap, intmax_t), p));
	else if (p->lenght == z)
		return (ft_put_int((long int)va_arg(*ap, long int), p));
	else
		return (ft_put_int((int)va_arg(*ap, int), p));
}

int			ft_print_ouxx(va_list *ap, t_param *p)
{
	uintmax_t	temp;

	if (p->lenght == hh)
		temp = (uintmax_t)va_arg(*ap, unsigned int);
	else if (p->lenght == h && (p->type == 'u' || p->type == 'U'))
		temp = (uintmax_t)va_arg(*ap, unsigned long);
	else if (p->lenght == h)
		temp = (uintmax_t)va_arg(*ap, unsigned int);
	else if (p->lenght == ll)
		temp = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (p->lenght == j)
		temp = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (p->lenght == l || p->lenght == z)
		temp = (uintmax_t)va_arg(*ap, unsigned long);
	else if (p->type == 'U' || p->type == 'O')
		temp = (uintmax_t)va_arg(*ap, unsigned long);
	else
		temp = (uintmax_t)va_arg(*ap, unsigned int);
	if (p->type == 'o' || p->type == 'O')
		return (ft_put_int_o(temp, p));
	if (p->type == 'u' || p->type == 'U')
		return (ft_put_int_u(temp, p));
	if (p->type == 'x' || p->type == 'X')
		return (ft_put_int_x(temp, p));
	return (0);
}

int			ft_print_ld(va_list *ap, t_param *p)
{
	if (p->lenght == ll)
		return (ft_put_int((intmax_t)va_arg(*ap, long long), p));
	else if (p->lenght == z)
		return (ft_put_int((intmax_t)va_arg(*ap, size_t), p));
	else if (p->lenght == j)
		return (ft_put_int((intmax_t)va_arg(*ap, long long), p));
	else if (p->lenght == l)
		return (ft_put_int((intmax_t)va_arg(*ap, long), p));
	else
		return (ft_put_int((intmax_t)va_arg(*ap, long), p));
}

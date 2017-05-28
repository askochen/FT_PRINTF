/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:08:22 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:08:25 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_int(t_param *param)
{
	if (param->type == 'i')
		return (1);
	if (param->type == 'd')
		return (1);
	if (param->type == 'D')
		return (1);
	if (param->type == 'o')
		return (1);
	if (param->type == 'O')
		return (1);
	if (param->type == 'u')
		return (1);
	if (param->type == 'U')
		return (1);
	if (param->type == 'x')
		return (1);
	if (param->type == 'X')
		return (1);
	return (0);
}

int		ft_print_int(va_list *ap, t_param *p)
{
	int		res;

	if (p->type == 'i' || p->type == 'd')
		res = ft_print_id(ap, p);
	if (p->type == 'D')
		res = ft_print_ld(ap, p);
	if (p->type == 'o' || p->type == 'u' || p->type == 'U' || p->type == 'O')
		res = ft_print_ouxx(ap, p);
	if (p->type == 'x' || p->type == 'X')
		res = ft_print_ouxx(ap, p);
	return (res);
}

int		ft_get_base(t_param *param)
{
	if (param->type == 'i' || param->type == 'd' || param->type == 'D')
		return (10);
	if (param->type == 'o' || param->type == 'O')
		return (8);
	if (param->type == 'u'  || param->type == 'U')
		return (10);
	if (param->type == 'x' || param->type == 'X')
		return (16);
	return (0);
}

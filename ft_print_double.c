/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:07:52 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:08:03 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_double(t_param *param)
{
	if (param->type == 'a')
		return (1);
	if (param->type == 'A')
		return (1);
	if (param->type == 'e')
		return (1);
	if (param->type == 'E')
		return (1);
	if (param->type == 'f')
		return (1);
	if (param->type == 'F')
		return (1);
	if (param->type == 'g')
		return (1);
	if (param->type == 'G')
		return (1);
	return (0);
}

int		ft_print_double(va_list *ap, t_param *param)
{
	double	temp;
	char	*str;

	temp = (double)va_arg(*ap, double);
	str = ft_dtoa_base(temp, 10);
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

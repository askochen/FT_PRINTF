/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:07:35 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:07:37 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_char(t_param* param)
{
	if (param->type == 'c')
		return (1);
	else
		return (0);
}

int 	ft_prit_char(va_list* ap, t_param* param)
{
	char*	temp;

	temp = ft_strnew(1);
	*temp = (char)va_arg(*ap, int);
	ft_print_left(temp, param->width, param->prec, param->left, ' ');
	return (1);
}

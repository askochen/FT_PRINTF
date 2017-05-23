/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:09:19 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:09:20 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_string(t_param* param)
{
	if (param->type == 's' || param->type == 'S')
		return (1);
	else
		return (0);
}

int		ft_print_str(va_list* ap, t_param* param)
{
	char*	str;
	int		len;
	
	if (param->type == 'c')
	{
		str = va_arg(*ap, char*);
		len = ft_strlen(str);
		ft_print_left(str, param->width, param->prec, param->left, ' ');
		return(len);
	}
	else
		return (ft_s_high(ap, param));
}

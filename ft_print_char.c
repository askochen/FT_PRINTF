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

int		ft_is_char(t_param *param)
{
	if (param->type == 'c' || param->type == 'C')
		return (1);
	else
		return (0);
}

int		ft_prit_char(va_list *ap, t_param *param)
{
	char		*temp;
	wchar_t		w_c;

	if (param->type == 'c')
	{
		temp = ft_strnew(1);
		*temp = (char)va_arg(*ap, int);
		ft_print_left(temp, 1, 1, param->left, ' ');
		free(temp);
		return (1);
	}
	else
	{
		w_c = (wchar_t)va_arg(*ap, void *);
		return (use_mask(w_c));
	}
}

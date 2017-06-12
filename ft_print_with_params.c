/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:10:18 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:10:26 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_with_params(va_list *ap, t_param *param)
{
	if (ft_is_persent(param))
		return (ft_print_persent(param));
	if (ft_is_string(param))
		return (ft_print_str(ap, param));
	if (ft_is_ptr(param))
		return (ft_print_ptr(ap, param));
	if (ft_is_char(param))
		return (ft_prit_char(ap, param));
	if (ft_is_int(param))
		return (ft_print_int(ap, param));
	if (ft_is_double(param))
		return (ft_print_double(ap, param));
	return (ft_error(param));
}

int		ft_is_persent(t_param *param)
{
	if (param->type == '%')
		return (1);
	else
		return (0);
}

int		ft_print_persent(t_param *param)
{
	char	*temp;
	int		len;
	char	symb;

	symb = ' ';
	if (param->left == 0 && param->zero == 1)
		symb = '0';
	temp = ft_strnew(1);
	temp[0] = '%';
	if (param->width > 0)
	{
		if (param->left == 1)
			temp = ft_insert_with_free(temp, ft_new_n_symb(param->width - 1, ' '), 1);
		else
			temp = ft_insert_with_free(temp, ft_new_n_symb(param->width - 1, symb), 0);
	}
	ft_putstr(temp);
	len = (int)ft_strlen(temp);
	return (len);
}

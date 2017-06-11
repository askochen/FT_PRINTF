/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:08:50 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:08:52 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_ptr(t_param *param)
{
	if (param->type == 'p')
		return (1);
	else
		return (0);
}

int		ft_print_ptr(va_list *ap, t_param *param)
{
	int 	*ptr;
	char	*str;
	char 	*temp;
	int		len;

	ptr = va_arg(*ap, int*);
	str = ft_itoa_base((intmax_t)ptr, 16);
	if (param->prec > (int)ft_strlen(str))
	{
		temp = ft_new_n_symb(param->prec - (int)ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp, 0);
	}
	str = ft_strjoin("0x", str);
	str = ft_modify_width_id(str, 2, param);
	len = (int)ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

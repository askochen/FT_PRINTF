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
	unsigned long long int	ptr;
	char					*str;
	char 					*temp;
	int						len;
	int 					pos;

	ptr = va_arg(*ap, unsigned int);
	str = ft_itoa_base(ptr, 16);
	str = ft_strjoin("0x", str);
	if (param->width > ft_strlen(str))
	{
		if (param->left == 1)
			pos = ft_strlen(str);
		else
			pos = 0;
		temp = ft_new_n_symb(param->width - ft_strlen(str), ' ');
		str = ft_insert_with_free(str, temp, pos);
	}
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

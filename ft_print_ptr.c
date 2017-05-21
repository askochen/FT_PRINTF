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

int		ft_is_ptr(t_param* param)
{
	if (param->type == 'p')
		return (1);
	else
		return (0);
}

int		ft_print_ptr(va_list* ap,t_param* param)
{
	unsigned int	ptr;
	char*			str;
	char*			temp;
	int				len;

	ptr = va_arg(*ap, unsigned int);
	temp = ft_itoa_base(ptr, 16);
	str = ft_strjoin("0x", temp);
	len = ft_strlen(str);

	ft_print_left(str, param->width, len, param->left, ' ');
	free(temp);
	free(str);
	return (len);
}

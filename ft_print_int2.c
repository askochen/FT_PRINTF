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

int	ft_print_id(va_list* ap,t_param* param)
{
	int temp;
	char* str;

	temp = (int)va_arg(*ap, int);
	str = ft_itoa_base(temp, 10);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_print_o(va_list* ap,t_param* param)
{
	unsigned int temp;
	char* str;

	temp = (unsigned int)va_arg(*ap, unsigned int);
	str = ft_itoa_base(temp, 8);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_print_u(va_list* ap,t_param* param)
{
	unsigned int temp;
	char* str;

	temp = (unsigned int)va_arg(*ap, unsigned int);
	str = ft_uitoa_base(temp, 10);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_print_xx(va_list* ap,t_param* param)
{
	unsigned int temp;
	char* str;
	char* temp_p;

	temp = (unsigned int)va_arg(*ap, unsigned int);
	str = ft_itoa_base(temp, 16);
	temp_p = str;
	if (param->type == 'X')
		while (*temp_p != '\0')
		{
			*temp_p = ft_toupper(*temp_p);
			++temp_p;
		}
	ft_putstr(str);
	return (ft_strlen(str));
}

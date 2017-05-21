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
	str = ft_itoa(temp);
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_print_ouxX(va_list* ap, t_param* p)
{
	unsigned long long temp;
	char* str;
	int len;

	if (p->lenght == hh)
		temp = (unsigned char)va_arg(*ap, int);
	else if (p->lenght == h)
		temp = (unsigned short)va_arg(*ap, int);
	else if (p->lenght == ll)
		temp = va_arg(*ap, unsigned long long);
	else if (p->lenght == l || p->lenght == j || p->lenght == z || p->type == 'O')
		temp = va_arg(*ap, unsigned long);
	else
		temp = (unsigned int)va_arg(*ap, unsigned int);
	str = ft_itoa_base(temp, ft_get_base(p));
	ft_add_xX(str, p);
	len = ft_normalize_ouxX(str, p);
	free(str);
	return (len);
}

int ft_normalize_ouxX(char* str, t_param* param)
{
	char symb;
	char* temp;
	char* temp1;
	int len; 

	symb = ' ';
	if (param->prec != 0 || param->zero == 1)
		symb = '0';
	if (param->prec > ft_strlen(str))
	{	
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), symb);
		temp = ft_strjoin(temp1, str);
		free(temp1);
		str = temp;
	}
	if (param->width > ft_strlen(str))
	{
		if ( param->left == 1)
		{
			temp1 = ft_new_n_symb(param->width - ft_strlen(str), ' ');
			temp = ft_strjoin(str, temp1);
		}
		else
		{
			temp1 = ft_new_n_symb(param->width - ft_strlen(str), symb);
			temp = ft_strjoin(temp1, str);	
		}
		free(temp1);
		str = temp;
	}
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}

void ft_add_xX(char* str, t_param* param)
{
	char* temp;

	temp = str;
	if (param->type == 'X')
	{
		while (*temp != '\0')
		{
			*temp = ft_toupper(*temp);
			++temp;
		}
	}
}
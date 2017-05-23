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

int	ft_print_id(va_list* ap,t_param* p)
{
	long long temp;
	int len;
	
	if (p->lenght == hh)
		temp = (signed char)va_arg(*ap, int);
	else if (p->lenght == h)
		temp = (short)va_arg(*ap, int);
	else if (p->lenght == ll)
		temp = va_arg(*ap, long long);
	else if (p->lenght == l)
		temp = (long)va_arg(*ap, long);
	else if (p->lenght == j)
		temp = (long long)va_arg(*ap, long long);
	else if (p->lenght == z)
		temp = (size_t)va_arg(*ap, size_t);
	else
		temp = (int)va_arg(*ap, int);
	len = ft_put_int(temp, p);
	return (len);
}

int	ft_print_D(va_list* ap,t_param* p)
{
	long long temp;
	int len;
	
	if (p->lenght == ll)
		temp = (long long)va_arg(*ap, long long);
	else if (p->lenght == z)
		temp = (size_t)va_arg(*ap, size_t);
	else if (p->lenght == j)
		temp = (long long)va_arg(*ap, long long);
	else if (p->lenght == l)
		temp = (long)va_arg(*ap, long);
	else
		temp = (long)va_arg(*ap, long);
	len = ft_put_int(temp, p);
	return (len);
}

int ft_put_int(long long num, t_param* param)
{
	int minus;
	char symb;
	int len;
	char* temp;
	char* temp1;
	char* str;

	symb = ' ';
	if (param->prec != 0 || param->zero == 1)
		symb = '0';
	minus = 0;
	if (num < 0)
	{
		num = num * -1;
		minus = 1;
	}
	str = ft_itoa_base(num,10);
	if (param->prec > ft_strlen(str))
	{	
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), symb);
		temp = ft_strjoin(temp1, str);
		free(temp1);
		str = temp;
	}
	if (minus)
		{
			temp = ft_strjoin("-", str);
			free(str);
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
			temp1 = ft_new_n_symb(param->width - ft_strlen(str), ' ');
			temp = ft_strjoin(temp1, str);	
		}
		free(temp1);
		str = temp;
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
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
	else if (p->lenght == l || p->lenght == j || p->lenght == z)
		temp = va_arg(*ap, unsigned long);
	else if (p->type == 'U' || p->type == 'O')
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
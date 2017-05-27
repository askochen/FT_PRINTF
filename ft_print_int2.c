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

int			ft_print_id(va_list *ap, t_param *p)
{
	long long	temp;

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
	return (ft_put_int(temp, p));
}

int			ft_print_ouxx(va_list *ap, t_param *p)
{
	unsigned long long	temp;

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
	if (p->type == 'o' || p->type == 'O')
		return (ft_put_int_o(temp, p));
	if (p->type == 'u' || p->type == 'U')
		return (ft_put_int_u(temp, p));
	if (p->type == 'x' || p->type == 'X')
		return (ft_put_int_x(temp, p));
	return (0);
}

int			ft_print_ld(va_list *ap, t_param *p)
{
	long long	temp;

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
	return (ft_put_int(temp, p));
}

int			ft_put_int(long long num, t_param *param)
{
	int			minus;
	int			len;
	char		*temp;
	char		*str;
	int 		pos;

	minus = 0;
	if (num < 0)
	{
		num = num * -1;
		minus = 1;
	}
	pos = 0;
	str = ft_itoa_base(num, 10);
	if (minus)
		str = ft_strjoin("-", str);
	else
		{
			if (param->sign == 1)
				str = ft_strjoin("+", str);
			else if (param->space == 1)
				str = ft_strjoin(" ", str);	
			}
	if (param->prec > ft_strlen(str))
	{
		if (minus == 1 || param->sign == 1 || param->space == 1)
		{
			pos = 1;
		}
		temp = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp, pos);
	}
	str = ft_modify_width_id(str, minus, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}


int 		ft_put_int_u(unsigned long long	temp, t_param* param)
{
	char 		*str;
	int 		len;
	char		*temp1;

	str = ft_itoa_base(temp, ft_get_base(param));
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, 0);
	}
	str = ft_modify_width_id(str, 0, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int 		ft_put_int_o(unsigned long long	temp, t_param* param)
{
	char 		*str;
	int 		len;
	char		*temp1;

	str = ft_itoa_base(temp, ft_get_base(param));
	if (param->altern == 1 && temp != 0)
		str = ft_strjoin("0", str);
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, 0);
	}
	str = ft_modify_width_id(str, 0, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int 		ft_put_int_x(unsigned long long	temp, t_param* param)
{
	char 		*str;
	int 		len;
	char		*temp1;

	str = ft_itoa_base(temp, ft_get_base(param));
	if (param->altern == 1)
		str = ft_strjoin("0x", str);
	ft_add_xx(str, param);
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, 2);
	}
	str = ft_modify_width_id(str, 2, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void		ft_add_xx(char *str, t_param *param)
{
	char	*temp;

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

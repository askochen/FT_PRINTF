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
	if (p->lenght == hh)
		return (ft_put_int((char)va_arg(*ap, int), p));
	else if (p->lenght == h)
		return (ft_put_int((short)va_arg(*ap, int), p));
	else if (p->lenght == ll)
		return (ft_put_int((long long)va_arg(*ap, long long), p));
	else if (p->lenght == l)
		return (ft_put_int((long)va_arg(*ap, long), p));
	else if (p->lenght == j)
		return (ft_put_int((intmax_t)va_arg(*ap, intmax_t), p));
	else if (p->lenght == z)
		return (ft_put_int((long int)va_arg(*ap, long int), p));
	else
		return (ft_put_int((int)va_arg(*ap, int), p));
}

int			ft_print_ouxx(va_list *ap, t_param *p)
{
	uintmax_t	temp;

	if (p->lenght == hh)
		temp = (uintmax_t)va_arg(*ap, unsigned int);
	else if (p->lenght == h)
		temp = (uintmax_t)va_arg(*ap, unsigned int);
	else if (p->lenght == ll)
		temp = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (p->lenght == j)
		temp = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (p->lenght == l || p->lenght == z)
		temp = (uintmax_t)va_arg(*ap, unsigned long);
	else if (p->type == 'U' || p->type == 'O')
		temp = (uintmax_t)va_arg(*ap, unsigned long);
	else
		temp = (uintmax_t)va_arg(*ap, unsigned int);
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
	if (p->lenght == ll)
		return (ft_put_int((intmax_t)va_arg(*ap, long long), p));
	else if (p->lenght == z)
		return (ft_put_int((intmax_t)va_arg(*ap, size_t), p));
	else if (p->lenght == j)
		return (ft_put_int((intmax_t)va_arg(*ap, long long), p));
	else if (p->lenght == l)
		return (ft_put_int((intmax_t)va_arg(*ap, long), p));
	else
		return (ft_put_int((intmax_t)va_arg(*ap, long), p));
}

int			ft_put_int(intmax_t num, t_param *param)
{
	int			minus;
	int			len;
	char		*temp;
	char		*str;
	int			pos;

	minus = 0;
	if (num < 0)
	{
		num = num * -1;
		minus = 1;
	}
	pos = 0;
	str = ft_itoa_base(num, 10);
	if (param->is_prec && num == 0 && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (param->prec > ft_strlen(str))
	{
		temp = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp, pos);
	}
	if (minus)
		str = ft_strjoin("-", str);
	else
	{
		if (param->sign == 1)
			str = ft_strjoin("+", str);
	}
	if (param->space == 1 && minus == 0 && param->sign == 0)
		str = ft_strjoin(" ", str);
	if (minus == 1 || param->sign == 1 || param->space == 1)
		pos = 1;
	str = ft_modify_width_id(str, pos, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_put_int_u(uintmax_t temp, t_param *param)
{
	char		*str;
	int			len;
	char		*temp1;

	str = ft_itoa_base(temp, ft_get_base(param));
	if (temp == 0 && param->is_prec && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
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

int		ft_put_int_o(uintmax_t temp, t_param *param)
{
	char		*str;
	int			len;
	char		*temp1;
	int			booll;

	str = ft_itoa_base(temp, ft_get_base(param));
	if (param->is_prec && temp == 0 && param->prec == 0 && param->altern == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	booll = param->altern == 1 && temp != 0;
	if (booll)
		str = ft_strjoin("0", str);
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, booll);
	}
	str = ft_modify_width_id(str, booll, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_put_int_x(uintmax_t temp, t_param *param)
{
	char		*str;
	int			len;
	char		*temp1;
	int			booll;

	str = ft_itoa_base(temp, ft_get_base(param));
	booll = param->altern == 1 && temp != 0;
	if (param->is_prec == 1 && temp == 0 && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (booll)
		str = ft_strjoin("0x", str);
	ft_add_xx(str, param);
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, 2 * booll);
	}
	str = ft_modify_width_id(str, 2 * booll, param);
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

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

/*
** return (ft_print_low_char(ap, p));
*/

/*
** return (ft_print_low_char(ap, p));
*/

/*
** return return (ft_print_hight_char(ap, p));
*/

int		ft_prit_char(va_list *ap, t_param *p)
{
	if (p->type == 'c' && p->lenght != l)
		return (ft_print_simple_ch(ap));
	else if (p->type == 'C' && p->lenght == l)
		return (ft_print_simple_ch(ap));
	else
		return (ft_print_simple_ch(ap));
}

int		ft_print_low_char(va_list *ap, t_param *p)
{
	char		*temp;
	int			len;
	int			is_null;

	is_null = 0;
	temp = ft_strnew(1);
	*temp = (char)va_arg(*ap, int);
	if (ft_isprint(*temp) == 0)
	{
		free(temp);
		temp = ft_strdup("");
		is_null = 1;
	}
	temp = ft_modify_with(p, temp, is_null);
	ft_putstr(temp);
	len = (int)ft_strlen(temp);
	if (is_null == 1)
		++len;
	free(temp);
	return (len);
}

int		ft_print_hight_char(va_list *ap, t_param *param)
{
	wchar_t		c;

	(void)param;
	c = (wchar_t)va_arg(*ap, void *);
	return (ft_print_w_char(c));
}

int		ft_print_simple_ch(va_list *ap)
{
	char	ch;

	ch = va_arg(*ap, int);
	ft_putchar(ch);
	return (1);
}

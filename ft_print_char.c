/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:37:18 by askochen          #+#    #+#             */
/*   Updated: 2017/06/08 17:37:23 by askochen         ###   ########.fr       */
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

char	ft_c(t_param *param)
{
	if (param->zero == 1 && param->left == 0)
		return ('0');
	else
		return (' ');
}

int		ft_prit_char(va_list *ap, t_param *p)
{
	if (p->type == 'c' && p->lenght != l)
		return (ft_print_low_char(ap, p));
		//return (ft_print_simple_ch(ap));
	else if (p->type == 'C' && p->lenght == l)
		return (ft_print_low_char(ap, p));
		//return (ft_print_simple_ch(ap));
	else
		return (ft_print_hight_char(ap, p));
}

int		ft_print_simple_ch(va_list *ap)
{
	char ch;

	ch = va_arg(*ap, int);
	ft_putchar(ch);
	return (1);
}

int		ft_print_low_char(va_list *ap, t_param *p)
{
	char		*temp;
	char		*temp1;
	int			len;
	int			pos;
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
	if (p->width > ft_strlen(temp))
	{
		//is_null = 0;
		if (p->left == 1)
			pos = ft_strlen(temp);
		else
			pos = 0;
		temp1 = ft_new_n_symb(p->width - ft_strlen(temp) - is_null, ft_c(p));
		temp = ft_insert_with_free(temp, temp1, pos);
	}
	ft_putstr(temp);
	len = ft_strlen(temp);
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
	return (use_mask(c));
}

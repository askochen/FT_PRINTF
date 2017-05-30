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

int		ft_prit_char(va_list *ap, t_param *p)
{
	// for site
	return (ft_print_low_ch(ap, p));

	//for test
/*	if (p->type == 'c'  && p->lenght != l) 
		return (ft_print_low_char(ap, p));
		//return (ft_print_simple_ch(ap));
	else if (p->type == 'C'  && p->lenght == l)
		return (ft_print_low_char(ap, p));
		//return (ft_print_simple_ch(ap));
	else
		return (ft_print_hight_char(ap, p));*/
}

int ft_print_simple_ch(va_list* ap)
{
	char ch;

	ch = va_arg(*ap, int);
	ft_putchar(ch);
	return (1);
}

int 	ft_print_low_char(va_list *ap, t_param *p)
{
	char		*temp;
	char 		*temp1;
	int 		len;
	int 		pos;

	temp = ft_strnew(1);
	*temp = (char)va_arg(*ap, int);
	if (*temp == 0)
	{
		free(temp);
		temp = ft_strnew(0);
	}
	if (p->width > ft_strlen(temp))
	{
		if (p->left == 1)
			pos = ft_strlen(temp);
		else
			pos = 0;
		temp1 = ft_new_n_symb(p->width - ft_strlen(temp), ' ');
		temp = ft_insert_with_free(temp, temp1, pos);
	}
	ft_putstr(temp);
	len = ft_strlen(temp);
	free(temp);
	return (len);
}

int 	ft_print_hight_char(va_list *ap, t_param *param)
{
	wchar_t		c;

	(void)param;
	c = (wchar_t)va_arg(*ap, void *);
	return (use_mask(c));
}

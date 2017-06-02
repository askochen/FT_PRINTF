/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:09:19 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:09:20 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_string(t_param *param)
{
	if (param->type == 's' || param->type == 'S')
		return (1);
	else
		return (0);
}

int			ft_print_str(va_list *ap, t_param *p)
{
	if (p->type == 's' && p->lenght != l)
		return (ft_print_low_str(ap, p));
	else if (p->type == 'S' && p->lenght == l)
		return (ft_print_low_str(ap, p));
	else
		return (ft_print_hight_str(ap, p));
}

int			ft_print_low_str(va_list *ap, t_param *p)
{
	char	*temp;
	char	*str;
	char	*temp1;
	int		len;
	int		pos;

	temp = va_arg(*ap, char*);
	if (temp != NULL)
		str = ft_strdup(temp);
	else
		str = ft_strdup("(null)");
	if (p->prec > 0)
		str = ft_cut_str(str, p->prec);
	if (p->width > ft_strlen(str))
	{
		if (p->left == 1)
			pos = ft_strlen(str);
		else
			pos = 0;
		temp1 = ft_new_n_symb(p->width - ft_strlen(str), ' ');
		str = ft_insert_with_free(str, temp1, pos);
	}
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int			w_char_len(wchar_t w_c)
{
	if (w_c <= 127)
		return (1);
	else if (w_c > 127 && w_c <= 2047)
		return (2);
	else if (w_c > 2047 && w_c <= 65535)
		return (3);
	else
		return (4);
}

int			ft_print_hight_str(va_list *ap, t_param *param)
{
	wchar_t		*s;
	int			n;
	int			i;

	i = 0;
	n = 0;
	s = (wchar_t *)va_arg(*ap, wchar_t *);
	while (s[i])
	{
		n += w_char_len(s[i]);
		use_mask(s[i]);
		++i;
	}
	return (n);
}

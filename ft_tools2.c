/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:45:29 by askochen          #+#    #+#             */
/*   Updated: 2017/06/12 16:45:40 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_set_symb(t_param *param)
{
	char	symb;

	if (param->zero == 1 && param->is_prec == 0 && param->left == 0)
		symb = '0';
	else
		symb = ' ';
	return (symb);
}

char	*ft_modify_width_id(char *str, int pos, t_param *param)
{
	char	*temp;

	if (param->width > (int)ft_strlen(str))
	{
		if (ft_set_symb(param) == ' ')
			pos = 0;
		if (param->left == 1)
			pos = (int)ft_strlen(str);
		temp = ft_new_n_symb(param->width - (int)ft_strlen(str), \
		ft_set_symb(param));
		str = ft_insert_with_free(str, temp, pos);
	}
	return (str);
}

char	*ft_modify_with(t_param *p, char *str, int is_null)
{
	char		*temp1;
	int			pos;
	int			len;

	if (p->width > (int)ft_strlen(str))
	{
		if (p->left == 1)
			pos = (int)ft_strlen(str);
		else
			pos = 0;
		len = p->width - (int)ft_strlen(str) - is_null;
		temp1 = ft_new_n_symb(len, ft_c(p));
		str = ft_insert_with_free(str, temp1, pos);
	}
	return (str);
}

char	ft_c(t_param *param)
{
	if (param->zero == 1 && param->left == 0)
		return ('0');
	else
		return (' ');
}

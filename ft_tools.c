/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:38:56 by askochen          #+#    #+#             */
/*   Updated: 2017/05/24 14:39:11 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_new_n_symb(int len, char symb)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(len);
	while (i < len)
	{
		str[i] = symb;
		++i;
	}
	return (str);
}

char	*ft_insert_with_free(char *str1, char *str2, int pos)
{
	int		len;
	char	*temp;
	int		i;
	char	*del1;
	char	*del2;

	del1 = str1;
	del2 = str2;
	len = ft_strlen(str1) + ft_strlen(str2);
	temp = ft_strnew(len);
	i = 0;
	if (pos < 0)
		pos = 0;
	if (pos > ft_strlen(str1))
		pos = ft_strlen(str1);
	while (i < len)
		if (i == pos)
			while (*str2 != '\0')
				temp[i++] = *(str2++);
		else
			temp[i++] = *(str1++);
	free(del1);
	free(del2);
	return (temp);
}

char	*ft_cut_str(char *str, int size)
{
	char		*temp;
	int			i;

	i = 0;
	if (size < 0)
		size = 0;
	if (size > ft_strlen(str))
		size = ft_strlen(str);
	temp = ft_strnew(size);
	while (i < size)
	{
		temp[i] = str[i];
		++i;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

char	ft_set_symb(t_param *param)
{
	char	symb;

	if (param->zero == 1 && param->prec == 0 && param->left == 0)
		symb = '0';
	else
		symb = ' ';
	return (symb);
}

char	*ft_modify_width_id(char *str, int pos, t_param *param)
{
	char	*temp;

	if (param->width > ft_strlen(str))
	{
		if (ft_set_symb(param) == ' ')
			pos = 0;
		if (param->left == 1)
			pos = ft_strlen(str);
		temp = ft_new_n_symb(param->width - ft_strlen(str), ft_set_symb(param));
		str = ft_insert_with_free(str, temp, pos);
	}
	return (str);
}

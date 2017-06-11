/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:11:18 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:11:39 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_error(t_param* param, char* str)
{	
/*	int		count;

	count = 0;
	if (param->left == 0)
		count = count + ft_fill_symbols(param);
	while (*str)
	{
		if (!ft_is_type(*str) && !ft_is_len(*str) && *str != '.' \
			&&  !ft_isdigit(*str) && !ft_is_flag(*str))
		{
			ft_putchar(*str);
			++count;
			++str;
			if (param->left == 1)
				count = count + ft_fill_symbols(param);
			while (!ft_is_type(*str) && *str)
			{
				ft_putchar(*str);
				++count;
				++str;
			}
		}
		++str;
	}
	return (count);*/

	param->count = param->count - 1;
	(void*)str;
	return (0);
}

int	ft_is_flag_exist(t_param* p)
{
	return (p->left || p->zero || p->space || p->sign || p->altern);
}

int ft_is_type(char ch)
{
	//	type -> d, i, o, u, x, X, f, F, e, E, g, G, a, A, s, S, p, n, %
	if (ch == 'a' || ch == 'A' || ch == 'o' || ch == 'O')
		return (1);
	if (ch == 'u' || ch == 'U' || ch == 'd' || ch == 'D')
		return (1);
	if (ch == 'X' || ch == 'x' || ch == 'f' || ch == 'F')
		return (1);
	if (ch == 'e' || ch == 'E' || ch == 'g' || ch == 'G')
		return (1);
	if (ch == 's' || ch == 'S' || ch == 'c' || ch == 'C')
		return (1);
	if (ch == 'i' || ch == 'p' || ch == 'n' || ch == '%')
		return (1);
	return (0);	
}

int ft_is_len(char ch)
{
	return (ch == 'l' || ch == 'h' || ch== 'j' || ch== 'z');
}

int	ft_fill_symbols(t_param* param)
{
	char	*str;
	int 	i;
	int 	len;

	i = 0;
	if ((param->width) <= 0)
		len = 0;
	else
		len = param->width - 1;
	str = ft_strnew(len);
	while (i < (len))
	{
		if (param->zero == 1 && param->left == 0) 
			str[i] = '0';
		else
			str[i] = ' ';
		++i;	
	}
	write(1, str, len);
	free(str);
	return (len);
}
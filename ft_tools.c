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

void	ft_put_n_symbols(char s, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		++i;
		ft_putchar(s);
	}
}

void	ft_put_str_n(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n && str[i] != '\0')
	{
		ft_putchar(str[i]);
		++i;
	}
}

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

void	ft_print_left(char *str, int size, int prec, int bool, char symb)
{
	int		len;

	len = ft_strlen(str);
	if (prec < 1)
		prec = len;
	if (len < size)
		if (bool == 1)
		{
			ft_put_str_n(str, prec);
			ft_put_n_symbols(symb, size - prec);
		}
		else
		{
			ft_put_n_symbols(symb, size - prec);
			ft_put_str_n(str, prec);
		}
	else
		ft_putstr(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_char_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:51:58 by askochen          #+#    #+#             */
/*   Updated: 2017/05/24 14:52:06 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_w_char_0(unsigned int val)
{
	unsigned char	temp;

	temp = val;
	write(1, &temp, 1);
	return (1);
}

int			ft_print_w_char_127(unsigned int val)
{
	unsigned char	temp;
	unsigned char	t1;
	unsigned char	t2;
	unsigned int	cons;

	cons = 49280;
	t2 = (val << 26) >> 26;
	t1 = ((val >> 6) << 27) >> 27;
	temp = (cons >> 8) | t1;
	write(1, &temp, 1);
	temp = ((cons << 24) >> 24) | t2;
	write(1, &temp, 1);
	return (2);
}

int			ft_print_w_char_2047(unsigned int val)
{
	unsigned char	temp;
	unsigned char	t1;
	unsigned char	t2;
	unsigned char	t3;
	unsigned int	cons;

	cons = 14712960;
	t3 = (val << 26) >> 26;
	t2 = ((val >> 6) << 26) >> 26;
	t1 = ((val >> 12) << 28) >> 28;
	temp = (cons >> 16) | t1;
	write(1, &temp, 1);
	temp = ((cons << 16) >> 24) | t2;
	write(1, &temp, 1);
	temp = ((cons << 24) >> 24) | t3;
	write(1, &temp, 1);
	return (3);
}

int			ft_print_w_char_biggest(unsigned int val, unsigned int cons)
{
	unsigned char	temp;
	unsigned char	t1;
	unsigned char	t2;
	unsigned char	t3;
	unsigned char	t4;

	t4 = (val << 26) >> 26;
	t3 = ((val >> 6) << 26) >> 26;
	t2 = ((val >> 12) << 26) >> 26;
	t1 = ((val >> 18) << 29) >> 29;
	temp = (cons >> 24) | t1;
	write(1, &temp, 1);
	temp = ((cons << 8) >> 24) | t2;
	write(1, &temp, 1);
	temp = ((cons << 16) >> 24) | t3;
	write(1, &temp, 1);
	temp = ((cons << 24) >> 24) | t4;
	write(1, &temp, 1);
	return (4);
}

int			ft_print_w_char(wchar_t val)
{
	unsigned int	temp;
	unsigned int	cons;

	cons = 4034953344;
	temp = val;
	if (val <= 127)
		return (ft_print_w_char_0(temp));
	else if (val <= 2047)
		return (ft_print_w_char_127(temp));
	else if (val <= 65535)
		return (ft_print_w_char_2047(temp));
	else
		return (ft_print_w_char_biggest(temp, cons));
}

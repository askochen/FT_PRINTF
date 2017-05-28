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

int		use_mask_0(unsigned int value, unsigned int mask)
{
	unsigned char	octet;

	(void)mask;
	octet = value;
	write(1, &octet, 1);
	return (1);
}

int		use_mask_1(unsigned int value, unsigned int mask)
{
	unsigned char	octet;
	unsigned char	o1;
	unsigned char	o2;

	o2 = (value << 26) >> 26;
	o1 = ((value >> 6) << 27) >> 27;
	octet = (mask >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o2;
	write(1, &octet, 1);
	return (2);
}

int		use_mask_2(unsigned int value, unsigned int mask)
{
	unsigned char	octet;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	o3 = (value << 26) >> 26;
	o2 = ((value >> 6) << 26) >> 26;
	o1 = ((value >> 12) << 28) >> 28;
	octet = (mask >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o3;
	write(1, &octet, 1);
	return (3);
}

int		use_mask_3(unsigned int value, unsigned int mask)
{
	unsigned char	octet;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	o4 = (value << 26) >> 26;
	o3 = ((value >> 6) << 26) >> 26;
	o2 = ((value >> 12) << 26) >> 26;
	o1 = ((value >> 18) << 29) >> 29;
	octet = (mask >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o4;
	write(1, &octet, 1);
	return (4);
}

int		use_mask(wchar_t value)
{
	unsigned int	v;
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	v = value;
	if (value <= 127)
		return (use_mask_0(v, 0));
	else if (value > 127 && value <= 2047)
		return (use_mask_1(v, mask1));
	else if (value > 2047 && value <= 65535)
		return (use_mask_2(v, mask2));
	else
		return (use_mask_3(v, mask3));
}
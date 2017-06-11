/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:06:47 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:06:49 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_base(uintmax_t nb, long long int base)
{
	if (nb == 0)
		return (1);
	if (nb < (uintmax_t)base)
		return (1);
	else
		return (ft_count_base(nb / base, base) + 1);
}

char	*ft_itoa_base(uintmax_t n, long long int base)
{
	int			len;
	char		*temp;
	char		*ptr;

	len = ft_count_base(n, base);
	ptr = ft_strnew(len);
	if (ptr == NULL)
		return (NULL);
	temp = ptr;
	while (len > 0)
	{
		if (n % base < 10)
			*(ptr + len - 1) = (n % base + '0');
		else
			*(ptr + len - 1) = (('a' + n % base) - 10);
		n = n / base;
		--len;
	}
	return (temp);
}

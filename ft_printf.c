/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:10:44 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:11:09 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_type(t_param *c_p, char *str)
{
	c_p->type = str[c_p->count];
	if (c_p->type != '\0')
		c_p->count = c_p->count + 1;
}

t_param		*ft_new_params(va_list *ap, char *str)
{
	t_param		*c_param;

	c_param = (t_param*)malloc(sizeof(t_param));
	ft_bzero((void*)c_param, sizeof(t_param));
	ft_parse_flags(c_param, str);
	ft_parse_width(c_param, str, ap);
	ft_parse_flags(c_param, str);
	while (*(str + c_param->count) == '.')
		ft_parse_precis(c_param, str, ap);
	ft_parse_flags(c_param, str);
	while (ft_is_len(*(str + c_param->count)))
		ft_parse_lenght(c_param, str);
	ft_parse_flags(c_param, str);
	ft_parse_type(c_param, str);
	return (c_param);
}

int			ft_parse_with_flags(va_list *ap, char *str, int *size)
{
	int			len;
	t_param		*param;

	param = ft_new_params(ap, str);
	*size = param->count + 1;
	len = ft_print_with_params(ap, param, str);
	free(param);
	return (len);
}

int			ft_parse(va_list *ap, char *str)
{
	int		len;
	int		res;
	int		size;

	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			res = ft_parse_with_flags(ap, str + 1, &size);
			str = str + size;
			len = len + res;
		}
		else
		{
			ft_putchar(*str);
			++str;
			++len;
		}
	}
	return (len);
}

int			ft_printf(char *str, ...)
{
	int			len;
	va_list		ap;

	len = 0;
	if (str != NULL)
	{
		va_start(ap, str);
		len = ft_parse(&ap, str);
		va_end(ap);
	}
	return (len);
}

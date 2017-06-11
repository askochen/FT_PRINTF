/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:07:05 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:07:14 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_lenght(t_param *param, char *str)
{
	if (ft_is_len_hh(param, str))
		return ;
	if (ft_is_len_ll(param, str))
		return ;
	if (ft_is_len_h(param, str))
		return ;
	if (ft_is_len_hh(param, str))
		return ;
	if (ft_is_len_j(param, str))
		return ;
	if (*(str + param->count) == 'z' && param->lenght < 7)
	{
		param->lenght = z;
		param->count = param->count + 1;
	}
}

void	ft_parse_precis(t_param *param, char *str, va_list *ap)
{
	int		prec;

	prec = 0;
	param->prec = 0;
	if (*(str + param->count) == '.')
	{
		param->is_prec = 1;
		param->count = param->count + 1;
		if (*(str + param->count) == '*')
		{
			param->count = param->count + 1;
			if ((prec = va_arg(*ap, int)) >= 0)
				param->prec = prec;
		}
		else
			while (ft_isdigit(*(str + param->count)))
			{
				param->prec = param->prec * 10 + (*(str + param->count) - '0');
				param->count = param->count + 1;
			}
	}
}

void	ft_parse_width(t_param *param, char *str, va_list *ap)
{
	int		temp;

	param->width = 0;
	if (*(str + param->count) == '*')
	{
		param->is_width = 1;
		temp = va_arg(*ap, int);
		if (temp < 0)
		{
			param->left = 1;
			param->width = -temp;
		}
		else
			param->width = temp;
		param->count = param->count + 1;
	}
	if (ft_isdigit(*(str + param->count)))
	{
		param->is_width = 1;
		while (ft_isdigit(*(str + param->count)))
		{
			param->width = param->width * 10 + (*(str + param->count) - '0');
			param->count = param->count + 1;
		}
	}
}

int		ft_is_flag(char c)
{
	if (c == '0' || c == '-' || c == '+' || c == ' ' || c == '#')
		return (1);
	else
		return (0);
}

void	ft_parse_flags(t_param *param, char *str)
{
	while (ft_is_flag(*(str + param->count)))
	{
		if (*(str + param->count) == '-')
			param->left = 1;
		if (*(str + param->count) == '+')
			param->sign = 1;
		if (*(str + param->count) == ' ')
			param->space = 1;
		if (*(str + param->count) == '0')
			param->zero = 1;
		if (*(str + param->count) == '#')
			param->altern = 1;
		param->count = param->count + 1;
	}
}


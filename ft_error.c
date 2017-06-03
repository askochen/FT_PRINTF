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

void ft_error(t_param* param)
{	param->count = param->count - 1;
	param->error = 1;
}

int	ft_is_flag_exist(t_param* p)
{
	return (p->left || p->zero || p->space || p->sign || p->altern);
}
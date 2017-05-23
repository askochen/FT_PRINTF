/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:11:18 by askochen          #+#    #+#             */
/*   Updated: 2017/05/18 14:11:39 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct	s_param
{
	//  flags -> ' ', '+', '-', '0', '#', 
	char		left;
	char		zero;
	char		space;
	char		sign;
	char		altern;

	//	width -> int or *
	int			width;

	//	precision -> int or *
	int			prec;

	//	lenght -> none, hh, ll, l, h, z, j
	enum		{none, hh, h, l, ll, j, z} lenght;

	//	type -> d, i, o, u, x, X, f, F, e, E, g, G, a, A, s, S, p, n, %
	char		type;

	// additional counter
	int			count;
}				t_param;


//	ft_printf.c
int			ft_printf(char* str, ...);
int			ft_parse(va_list* ap, char* str);
t_param*	ft_new_params(va_list* ap, char* str);
int			ft_parse_with_flags(va_list* ap, char* str, int* size);
void		ft_parse_type(t_param* c_param, char* str);

//	ft_parse_param.c
void		ft_parse_lenght(t_param* param, char* str);
void		ft_parse_precis(t_param* param, char* str, va_list* ap);
void		ft_parse_width(t_param* param, char* str, va_list* ap);
int			ft_is_flag(char c);
void		ft_parse_flags(t_param* param, char* str);

//	ft_print_with_params.c
int			ft_print_with_params(va_list* ap, t_param* param);
int			ft_is_persent(t_param* param);
int			ft_print_persent();

//	tools.c
void		ft_put_n_symbols(char symb, int n);
void		ft_put_str_n(char*  str, int n);
void		ft_print_left(char* str, int size, int prec, int bool, char symb);
char*		ft_new_n_symb(int len, char symb);

// ft_print_string.c
int			ft_is_string(t_param* param);
int			ft_print_str(va_list* ap, t_param* param);

//	ft_print_char.c
int			ft_is_char(t_param* param);
int			ft_prit_char(va_list* ap, t_param* param);

//	ft_print_ptr.c
int			ft_is_ptr(t_param* param);
int			ft_print_ptr(va_list* ap,t_param* param);
int			ft_get_base(t_param* param);

//	ft_print_int.c
int			ft_is_int(t_param* param);
int			ft_print_int(va_list* ap, t_param* param);

//	ft_printf_int2.c
int			ft_print_id(va_list* ap,t_param* param);
int			ft_print_ouxX(va_list* ap,t_param* param);
int			ft_normalize_ouxX(char* str, t_param* param);
void		ft_add_xX(char* str, t_param* param);
int			ft_put_int(long long num, t_param* param);
int			ft_print_D(va_list* ap,t_param* p);
//	ft_print_double.c
int			ft_is_double(t_param* param);
int			ft_print_double(va_list* ap, t_param* param);

//	ft_itoa_base.c
int			ft_count_base(long long int nb, long long int base);
char*		ft_itoa_base(long long int n, long long int base);

//	ft_ftoa_base.c
char		*ft_dtoa_base(double value, int base);
#endif

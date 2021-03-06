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
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct						s_param
{
	char							left;
	char							zero;
	char							space;
	char							sign;
	char							altern;
	int								width;
	int								is_width;
	int								prec;
	int								is_prec;
	enum {none, hh, h, l, ll, j, z}	lenght;
	char							type;
	int								count;
	int								error;
}									t_param;

int									ft_printf(char *str, ...);
int									ft_parse(va_list *ap, char *str);
t_param								*ft_new_params(va_list *ap, char *str);
int									ft_parse_with_flags(va_list *ap,
									char *str, int *size);
void								ft_parse_type(t_param *c_param, char *str);
void								ft_parse_lenght(t_param *param, char *str);
void								ft_parse_precis(t_param *param,
									char *str, va_list *ap);
void								ft_parse_width(t_param *param,
									char *str, va_list *ap);
int									ft_is_flag(char c);
void								ft_parse_flags(t_param *param, char *str);
void								ft_set_hh(t_param *param);
void								ft_set_h(t_param *param);
void								ft_set_ll(t_param *param);
void								ft_set_l(t_param *param);
void								ft_set_j(t_param *param);
int									ft_print_with_params(va_list *ap,
									t_param *param);
int									ft_is_persent(t_param *param);
int									ft_print_persent(t_param *param);
char								*ft_new_n_symb(int len, char symb);
char								*ft_insert_with_free(char *str1,
									char *str2, int pos);
char								*ft_cut_str(char *str, int size);
char								*ft_modify_width_id(char *str,
									int minus, t_param *param);
char								ft_set_symb(t_param *param);
char								*ft_modify_prec_id(char *str,
									t_param *param);
char								*ft_modify_sing(char *str, t_param *param,
									int minus);
char								*ft_get_string(intmax_t num,
									t_param *param, int *minus);
int									ft_is_string(t_param *param);
int									ft_print_str(va_list *ap, t_param *param);
int									ft_print_low_str(va_list *ap, t_param *p);
int									w_char_len(wchar_t w_c);
int									ft_print_hight_str(va_list *ap,
									t_param *param);
int									ft_is_char(t_param *param);
int									ft_prit_char(va_list *ap, t_param *param);
int									ft_print_low_char(va_list *ap, t_param *p);
int									ft_print_hight_char(va_list *ap,
									t_param *param);
char								ft_c(t_param *param);
int									ft_print_w_char_0(unsigned int val);
int									ft_print_w_char_127(unsigned int val);
int									ft_print_w_char_2047(unsigned int val);
int									ft_print_w_char_biggest(unsigned int val,
									unsigned int cons);
int									ft_print_w_char(wchar_t w_c);
int									ft_is_ptr(t_param *param);
int									ft_print_ptr(va_list *ap, t_param *param);
int									ft_is_int(t_param *param);
int									ft_print_int(va_list *ap, t_param *param);
int									ft_get_base(t_param *param);
int									ft_print_id(va_list *ap, t_param *param);
int									ft_print_ouxx(va_list *ap, t_param *param);
int									ft_print_ld(va_list *ap, t_param *p);
int									ft_put_int(intmax_t num, t_param *param);
int									ft_put_int_u(uintmax_t	temp,
									t_param *param);
int									ft_put_int_o(uintmax_t	temp,
									t_param *param);
int									ft_put_int_x(uintmax_t	temp,
									t_param *param);
void								ft_add_xx(char *str, t_param *param);
int									ft_is_double(t_param *param);
int									ft_print_double(va_list *ap,
									t_param *param);
int									ft_count_base(uintmax_t nb,
									long long int base);
char								*ft_itoa_base(uintmax_t n,
									long long int base);
char								*ft_dtoa_base(double value, int base);
int									ft_error(t_param *param);
int									ft_is_flag_exist(t_param *p);
int									ft_is_type(char ch);
int									ft_is_len(char ch);
int									ft_fill_symbols(t_param *param);
char								*ft_modify_with(t_param *p, char *str,
									int is_null);
int									ft_print_simple_ch(va_list *ap);
#endif

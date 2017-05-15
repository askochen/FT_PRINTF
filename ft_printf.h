#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>

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

	//	lenght -> hh, ll, l, h, z, j
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

// ft_print_string.c
int			ft_is_string(t_param* param);
int			ft_print_str(va_list* ap, t_param* param);

//	ft_print_char.c
int			ft_is_char(t_param* param);
int			ft_prit_char(va_list* ap, t_param* param);

//	ft_print_ptr.c
int			ft_is_ptr(t_param* param);
int			ft_print_ptr(va_list* ap,t_param* param);

//	ft_print_int.c
int			ft_is_int(t_param* param);
int			ft_print_int(va_list* ap, t_param* param);

//	ft_print_float.c
int			ft_is_float(t_param* param);
int			ft_print_float(va_list* ap, t_param* param);

//	ft_print_double.c
int			ft_is_double(t_param* param);
int			ft_print_double(va_list* ap, t_param* param);

//	ft_itoa_base.c
int			ft_count(long long int nb);
char*		ft_itoa_new(long long int nb);
int			ft_count_base(long long int nb, long long int base);
char*		ft_itoa_base(long long int n, long long int base);

//	ft_ftoa_base.c
char		*ft_dtoa_base(double value, int base);
#endif
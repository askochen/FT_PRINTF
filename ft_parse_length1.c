#include "ft_printf.h"

int 		ft_is_len_hh(t_param *param, char *str)
{
	if ((*(str + param->count) == 'h') && (*(str + param->count + 1) == 'h') \
		&& param->lenght < 2)
	{
		param->lenght = hh;
		param->count = param->count + 2;
		return (1);
	}
	return (0);
}
int 		ft_is_len_h(t_param *param, char *str)
{
	if (*(str + param->count) == 'h' && param->lenght < 5)
	{
		param->lenght = h;
		param->count = param->count + 1;
		return(1);
	}
	return (0);
}
int 		ft_is_len_ll(t_param *param, char *str)
{
	if ((*(str + param->count) == 'l') && (*(str + param->count + 1) == 'l') \
		&& param->lenght < 3)
	{
		param->lenght = ll;
		param->count = param->count + 2;
		return (1);
	}
	return (0);
}
int 		ft_is_len_l(t_param *param, char *str)
{
	if (*(str + param->count) == 'l' && param->lenght < 4)
	{
		param->lenght = l;
		param->count = param->count + 1;
		return (1);
	}
	return (0);
}
int 		ft_is_len_j(t_param *param, char *str)
{
	if (*(str + param->count) == 'j' && param->lenght < 6)
	{
		param->lenght = j;
		param->count = param->count + 1;
		return (1);
	}
	return (0);
}
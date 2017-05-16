#include "ft_printf.h"

int		ft_is_int(t_param* param)
{
	if (param->type == 'i')
		return (1);
	if (param->type == 'd')
		return (1);
	if (param->type == 'o')
			return (1);
	if (param->type == 'u')
			return (1);
	if (param->type == 'x')
			return (1);
	if (param->type == 'X')
		return (1);
	return (0);
}

int		ft_print_int(va_list* ap,t_param* param)
{
	int		res;

	if (param->type == 'i' || param->type == 'd')
		res = ft_print_id(ap, param);
	if (param->type == 'o')
		res = ft_print_o(ap, param);
	if (param->type == 'u')
		res = ft_print_u(ap, param);
	if (param->type == 'x' || param->type == 'X')
		res = ft_print_xx(ap, param);
	return (res);
}
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
	int		temp;
	char*	str;

	temp = (char)va_arg(*ap, int);
	str = ft_itoa(temp);
	ft_putstr(str); 
	return (ft_strlen(str));
}
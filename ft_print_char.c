#include "ft_printf.h"

int		ft_is_char(t_param* param)
{
	if (param->type == 'c')
		return (1);
	else
		return (0);
}

int 	ft_prit_char(va_list* ap, t_param* param)
{
	char	temp;

	temp = (char)va_arg(*ap, int);
	ft_putchar(temp);
	return (1);
}
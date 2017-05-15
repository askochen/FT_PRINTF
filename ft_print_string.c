#include "ft_printf.h"

int		ft_is_string(t_param* param)
{
	if (param->type == 's' || param->type == 'S')
		return (1);
	else
		return (0);
}

int		ft_print_str(va_list* ap, t_param* param)
{
	char*	str;
	int		len;
	
	str = va_arg(*ap, char*);
	len = ft_strlen(str);
	ft_putstr(str);
	return(len);
}
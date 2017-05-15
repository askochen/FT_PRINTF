#include "ft_printf.h"

int		ft_is_ptr(t_param* param)
{
	if (param->type == 'p')
		return (1);
	else
		return (0);
}

int		ft_print_ptr(va_list* ap,t_param* param)
{
	unsigned int	ptr;
	char*			str;
	char*			temp;
	int				len;

	ptr = va_arg(*ap, unsigned int);
	temp = ft_itoa_base(ptr, 16);
	str = ft_strjoin("0x", temp);
	len = ft_strlen(str);
	ft_putstr(str);
	free(temp);
	free(str);
	return (len);
}

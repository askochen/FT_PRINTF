#include "ft_printf.h"

char	ft_set_symb(t_param *param)
{
	char	symb;

	if (param->zero == 1 && param->is_prec == 0 && param->left == 0)
		symb = '0';
	else
		symb = ' ';
	return (symb);
}

char	*ft_modify_width_id(char *str, int pos, t_param *param)
{
	char	*temp;

	if (param->width > (int)ft_strlen(str))
	{
		if (ft_set_symb(param) == ' ')
			pos = 0;
		if (param->left == 1)
			pos = (int)ft_strlen(str);
		temp = ft_new_n_symb(param->width - (int)ft_strlen(str), \
		 ft_set_symb(param));
		str = ft_insert_with_free(str, temp, pos);
	}
	return (str);
}

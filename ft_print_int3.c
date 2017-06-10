
#include "ft_printf.h"

int			ft_put_int(intmax_t num, t_param *param)
{
	int			minus;
	int			len;
	char		*temp;
	char		*str;
	int			pos;
	
	str = ft_get_string(num, param, &minus);
	pos = 0;
	if (param->prec > ft_strlen(str))
	{
		temp = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp, pos);
	}
	str = ft_modify_sing(str, param, minus);
	if (param->space == 1 && minus == 0 && param->sign == 0)
		str = ft_strjoin(" ", str);
	if (minus == 1 || param->sign == 1 || param->space == 1)
		pos = 1;
	str = ft_modify_width_id(str, pos, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_put_int_u(uintmax_t temp, t_param *param)
{
	char		*str;
	int			len;
	char		*temp1;

	str = ft_itoa_base(temp, ft_get_base(param));
	if (temp == 0 && param->is_prec && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, 0);
	}
	str = ft_modify_width_id(str, 0, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_put_int_o(uintmax_t temp, t_param *param)
{
	char		*str;
	int			len;
	char		*temp1;
	int 		bool;

	str = ft_itoa_base(temp, ft_get_base(param));
	if (param->is_prec && temp == 0 && param->prec == 0 && param->altern == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	bool = param->altern == 1 && temp != 0;
	if (bool)
		str = ft_strjoin("0", str);
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, bool);
	}
	str = ft_modify_width_id(str, bool, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		ft_put_int_x(uintmax_t temp, t_param *param)
{
	char		*str;
	int			len;
	char		*temp1;
	int 		bool;

	str = ft_itoa_base(temp, ft_get_base(param));
	bool = param->altern == 1 && temp != 0;
	if (param->is_prec == 1 && temp == 0 && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (bool)
		str = ft_strjoin("0x", str);
	ft_add_xx(str, param);
	if (param->prec > ft_strlen(str))
	{
		temp1 = ft_new_n_symb(param->prec - ft_strlen(str), '0');
		str = ft_insert_with_free(str, temp1, 2 * bool);
	}
	str = ft_modify_width_id(str, 2 * bool, param);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void		ft_add_xx(char *str, t_param *param)
{
	char	*temp;

	temp = str;
	if (param->type == 'X')
	{
		while (*temp != '\0')
		{
			*temp = ft_toupper(*temp);
			++temp;
		}
	}
}

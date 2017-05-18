#include "ft_printf.h"

void ft_put_n_symbols(char s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		++i;
		ft_putchar(s);
	}
}

void ft_put_str_n(char*  str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(str[i]);
		++i;
	}
}

void ft_print_left(char* str, int size, int prec, int bool, char symb)
{
	int		len;

	len = ft_strlen(str);
	if (prec < 1)
		prec = len;
	if (len < size)
		if (bool == 1)
		{	
			ft_put_str_n(str, prec);
			ft_put_n_symbols(symb, size - prec);
		}
		else
		{
			ft_put_n_symbols(symb, size - prec);
			ft_put_str_n(str, prec);
		}
	else
		ft_putstr(str);
}
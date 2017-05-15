#include "ft_printf.h"

char		*ft_dtoa_base(double value, int base)
{
	char	*str;
	char	*p;
	float	val;

	str = ft_itoa_base((long long)value, (long long)base);
	val = value - (long)value;
	if (val == 0)
		return (str);
	p = str;
	while (*p != '\0')
		++p;
	*p = '.';
	*(p + 1) = '\0';
	val = (int)(val * 1000000 + 1);
	str = ft_strjoin(str, ft_itoa_base((long long)val, (long long)base));
	return (str);
}
#include "ft_printf.h"
#include <unistd.h>

int		ft_count(long long int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (ft_count(-nb) + 1);
	if (nb < 10)
		return (1);
	else
		return(ft_count(nb / 10) + 1);
}

char	*ft_itoa_new(long long int nb)
{
	int			len;
	char		*temp;
	long int	n;
	char		*ptr;

	n = nb;
	len = ft_count(n);
	temp = ft_strnew(len);
	ptr = temp;
	if (n < 0)
	{
		*ptr = '-';
		++ptr;
		--len;
		n = n * -1;
	}
	while(len > 0)
	{
		*(ptr + len - 1) = n % 10 + '0';
		n = n / 10;
		--len;
	}
	return (temp);
}

int		ft_count_base(long long int nb, long long int base)
{
	if (nb == 0)
		return (1);
	if (nb < base)
		return (1);
	else
		return(ft_count_base(nb / base, base) + 1);
}

char	*ft_itoa_base(long long int n, long long int base)
{
	int			len;
	char		*temp;
	char		*ptr;

	if (base == 10)
	{
		ptr = ft_itoa_new(n);
		return (ptr);
	}
	if (n < 0)
		n = n * -1;
	len = ft_count_base(n, base);
	ptr = ft_strnew(len);
	if (ptr == NULL)
		return (NULL);
	temp = ptr;
	while(len > 0)
	{
		if (n % base < 10)
			*(ptr + len - 1) = (n % base + '0');
		else
			*(ptr + len - 1) = (('a' + n % base) - 10);
		n = n / base;
		--len;
	}
	return (temp);
}

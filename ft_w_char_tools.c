#include "ft_printf.h"

int		use_mask_0(unsigned int w_c, unsigned int mask)
{
	unsigned char	temp;

	(void)mask;
	temp = w_c;
	write(1, &temp, 1);
	return (1);
}

int		use_mask_1(unsigned int w_c, unsigned int mask)
{
	unsigned char	temp;
	unsigned char	p1;
	unsigned char	p2;

	p2 = (w_c << 26) >> 26;
	p1 = ((w_c >> 6) << 27) >> 27;
	temp = (mask >> 8) | p1;
	write(1, &temp, 1);
	temp = ((mask << 24) >> 24) | p2;
	write(1, &temp, 1);
	return (2);
}

int		use_mask_2(unsigned int w_c, unsigned int mask)
{
	unsigned char	temp;
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;

	p3 = (w_c << 26) >> 26;
	p2 = ((w_c >> 6) << 26) >> 26;
	p1 = ((w_c >> 12) << 28) >> 28;
	temp = (mask >> 16) | p1;
	write(1, &temp, 1);
	temp = ((mask << 16) >> 24) | p2;
	write(1, &temp, 1);
	temp = ((mask << 24) >> 24) | p3;
	write(1, &temp, 1);
	return (3);
}

int		use_mask_3(unsigned int w_c, unsigned int mask)
{
	unsigned char	temp;
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	unsigned char	p4;

	p4 = (w_c << 26) >> 26;
	p3 = ((w_c >> 6) << 26) >> 26;
	p2 = ((w_c >> 12) << 26) >> 26;
	p1 = ((w_c >> 18) << 29) >> 29;
	temp = (mask >> 24) | p1;
	write(1, &temp, 1);
	temp = ((mask << 8) >> 24) | p2;
	write(1, &temp, 1);
	temp = ((mask << 16) >> 24) | p3;
	write(1, &temp, 1);
	temp = ((mask << 24) >> 24) | p4;
	write(1, &temp, 1);
	return (4);
}

int		use_mask(wchar_t w_c)
{
	unsigned int	temp;
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	temp = w_c;
	if (w_c <= 127)
		return (use_mask_0(temp, 0));
	else if (w_c > 127 && w_c <= 2047)
		return (use_mask_1(temp, mask1));
	else if (w_c > 2047 && w_c <= 65535)
		return (use_mask_2(temp, mask2));
	else
		return (use_mask_3(temp, mask3));
}

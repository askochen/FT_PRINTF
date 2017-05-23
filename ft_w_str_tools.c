#include "ft_printf.h"

int			w_char_len(wchar_t w_c)
{
	if (w_c <= 127)
		return (1);
	else if (w_c > 127 && w_c <= 2047)
		return (2);
	else if (w_c > 2047 && w_c <= 65535)
		return (3);
	else
		return (4);
}

int			ft_s_high(va_list* ap, t_param* param)
{
	wchar_t		*s;
	int			n;
	int			i;

	i = 0;
	n = 0;
	s = (wchar_t *)va_arg(*ap, wchar_t *);

		while (s[i])
		{
			n += w_char_len(s[i]);
			use_mask(s[i]);
			++i;
		}

	return (n);
}
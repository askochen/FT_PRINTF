#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char* str = "qwerty";
	printf("%-10.3s @\n", str);
	ft_printf("%-10.3s @\n", str);
	return (0);
}
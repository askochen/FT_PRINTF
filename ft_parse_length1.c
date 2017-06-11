#include "ft_printf.h"

void 		ft_set_hh(t_param *param)
{
	if (param->lenght < 2)
		param->lenght = hh;
	param->count = param->count + 2;
}
void 		ft_set_h(t_param *param)
{
	if (param->lenght < 5)
		param->lenght = h;
	param->count = param->count + 1;
}
void 		ft_set_ll(t_param *param)
{
	if (param->lenght < 3)
		param->lenght = ll;
	param->count = param->count + 2;
}
void 		ft_set_l(t_param *param)
{
	if (param->lenght < 4)
		param->lenght = l;
	param->count = param->count + 1;
}
void 		ft_set_j(t_param *param)
{
	if (param->lenght < 6)
		param->lenght = j;
	param->count = param->count + 1;
}
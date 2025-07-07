#include "tstr.h"

char	ft_tstr_pop(t_string *str)
{
	char	o;

	if (!str || !str->data || !str->len)
		return (0);
	o = ft_tstr_borrow(str)[str->len - 1];
	str->data[str->len - 1] = 0;
	str->len--;
	return (o);
}

#include "lft.h"

void	ft_tstr_free(t_string *str)
{
	void	*tmp;

	if (str->data)
	{
		tmp = str->data;
		ft_free(&tmp);
		str->data = NULL;
	}
	str->len = 0;
	str->alloc_size = 0;
}

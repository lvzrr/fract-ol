#include "tstr.h"

void	ft_tstr_reserve(t_string *str, size_t n)
{
	char	*new;

	if (!str || !str->data || n == 0)
		return ;
	if (str->alloc_size >= str->len + n)
		return ;
	new = ft_extend_zero(str->data, str->alloc_size, n);
	if (!new)
		return ;
	str->data = new;
	str->alloc_size += n;
}

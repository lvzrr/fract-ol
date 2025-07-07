#include "tstr.h"

void	ft_tstr_pushstr(t_string *str, const char *s)
{
	size_t	len;
	size_t	needed;
	char	*new_data;

	if (!str || !s)
		return ;
	len = ft_strlen(s);
	needed = str->len + len + 1;
	if (needed > str->alloc_size)
	{
		new_data = ft_extend_zero(str->data, str->alloc_size,
				(needed - str->alloc_size) * 2);
		if (!new_data)
			return ;
		str->data = new_data;
		str->alloc_size = needed;
	}
	ft_memmove(str->data + str->len, s, len);
	str->len += len;
	str->data[str->len] = 0;
}

void	ft_tstr_pushslice(t_string *str, const char *s, size_t n)
{
	size_t	len;
	size_t	needed;
	char	*new_data;

	if (!str || !s)
		return ;
	len = n;
	needed = str->len + len + 1;
	if (needed > str->alloc_size)
	{
		new_data = ft_extend_zero(str->data, str->alloc_size,
				(needed - str->alloc_size) * 2);
		if (!new_data)
			return ;
		str->data = new_data;
		str->alloc_size = needed;
	}
	ft_memmove(str->data + str->len, s, len);
	str->len += len;
	str->data[str->len] = 0;
}

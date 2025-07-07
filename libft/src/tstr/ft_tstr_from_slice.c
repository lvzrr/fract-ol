#include "tstr.h"

t_string	ft_tstr_from_slice(char *s, size_t n)
{
	t_string	out;

	if (!s)
	{
		out.len = 0;
		out.alloc_size = 1;
		out.data = ft_alloc(1);
		ft_memset(out.data, 0, 1);
	}
	else
	{
		out.len = n;
		out.alloc_size = out.len + 1;
		out.data = ft_memclone(s, out.len);
		ft_memset(out.data, 0, out.alloc_size);
		if (out.data)
			ft_memmove(out.data, s, out.len);
	}
	return (out);
}

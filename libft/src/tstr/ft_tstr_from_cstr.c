#include "lft.h"

t_string	ft_tstr_from_cstr(const char *str)
{
	t_string	out;

	if (!str)
	{
		out.len = 0;
		out.alloc_size = 1;
		out.data = ft_alloc(1);
		ft_memset(out.data, 0, 1);
	}
	else
	{
		out.len = ft_strlen(str);
		out.alloc_size = out.len + 1;
		out.data = ft_alloc(out.alloc_size);
		ft_memset(out.data, 0, out.alloc_size);
		if (out.data)
			ft_memcpy(out.data, str, out.len);
	}
	return (out);
}

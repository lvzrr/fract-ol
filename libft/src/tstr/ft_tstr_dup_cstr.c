#include "lft.h"

char	*ft_tstr_dup_cstr(t_string *str)
{
	if (!str || !str->data)
		return (NULL);
	return (ft_memclone(str->data, str->alloc_size));
}

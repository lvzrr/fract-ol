#include "cstr.h"

char	*ft_strdup(const char *str)
{
	size_t	n;

	if (!str)
		return (NULL);
	n = ft_strlen(str);
	return (ft_memclone((void *)str, n + 1));
}

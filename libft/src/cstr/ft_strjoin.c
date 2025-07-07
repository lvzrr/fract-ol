#include "cstr.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			l1;
	size_t			l2;
	char			*out;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	out = ft_alloc(l1 + l2 + 1);
	if (!out)
		return (NULL);
	ft_memcpy(out, s1, l1);
	ft_memcpy(out + l1, s2, l2);
	out[l1 + l2] = 0;
	return (out);
}

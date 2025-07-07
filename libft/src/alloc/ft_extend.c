#include "alloc.h"

void	*ft_extend(void *ptr, size_t n, size_t size)
{
	unsigned char	*p2;

	if (size > SIZE_MAX - n || (size == 0 && ptr))
		return (ft_free(&ptr), NULL);
	if (!ptr)
		return (ft_alloc(n + size));
	p2 = ft_alloc(n + size);
	if (!p2)
		return (NULL);
	ft_memmove(p2, ptr, n);
	return (ft_free(&ptr), p2);
}

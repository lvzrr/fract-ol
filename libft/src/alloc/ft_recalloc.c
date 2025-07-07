#include "alloc.h"

void	*ft_recalloc(void *ptr, size_t n, size_t size)
{
	void	*p;

	if (!size)
		return (ft_free(&ptr), NULL);
	if (!ptr)
		return (ft_calloc(size, 1));
	p = ft_calloc(size, 1);
	if (!p)
		return (ft_free(&ptr), NULL);
	if (size < n)
		n = size;
	ft_memmove(p, ptr, n);
	if (ptr)
		ft_free(&ptr);
	return (p);
}

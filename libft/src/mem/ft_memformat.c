#include "mem.h"

void	*ft_memformat(void *ptr, size_t size)
{
	void	*fmt;

	if (!ptr || !size)
		return (NULL);
	fmt = ft_memclone(ptr, size);
	return (free(ptr), fmt);
}

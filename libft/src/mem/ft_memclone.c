#include "mem.h"

void	*ft_memclone(void *__restrict__ ptr, size_t size)
{
	void	*new_reg;

	if (!ptr || size == 0)
		return (NULL);
	new_reg = ft_alloc(size);
	if (!new_reg)
		return (NULL);
	ft_memmove(new_reg, ptr, size);
	return (new_reg);
}

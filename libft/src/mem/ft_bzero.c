#include "mem.h"

void	ft_bzero(void *__restrict__ ptr, size_t n)
{
	ft_memset(ptr, 0, n);
}

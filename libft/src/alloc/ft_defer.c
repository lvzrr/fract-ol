#include "alloc.h"

void	ft_defer(void *p)
{
	ft_free((void **)p);
}

void	ft_defer_arr(void ***p)
{
	ft_free_array((void ***)p);
}

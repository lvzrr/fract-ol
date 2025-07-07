#include "mem.h"

void	ft_membroadcast(void *dst, void *src, size_t chunks, size_t n)
{
	size_t	i;

	if (!dst || !src || !chunks || !n)
		return ;
	i = 0;
	while (i + (2 * chunks) < n)
	{
		ft_memcpy((t_u8 *)dst + i, src, chunks);
		i += chunks;
		ft_memcpy((t_u8 *)dst + i, src, chunks);
		i += chunks;
	}
	while (i < n)
	{
		ft_memcpy((t_u8 *)dst + i, src, chunks);
		i += chunks;
	}
}

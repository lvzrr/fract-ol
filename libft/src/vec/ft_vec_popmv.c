#include "vec.h"

inline t_u8	ft_vec_popmv(void *__restrict__ dst,
	t_vec *__restrict__ v)
{
	if (!dst || !v || !v->alloc_size || !v->size)
		return (0);
	ft_memtake(dst, ft_vec_peek_last(v), v->sizeof_type);
	v->size--;
	return (1);
}

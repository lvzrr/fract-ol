#include "vec.h"

void	ft_vec_fit(t_vec *v)
{
	void	*data;

	if (!v || !v->size || !v->alloc_size)
		return ;
	data = ft_realloc(v->data, v->alloc_size * v->sizeof_type,
			v->size * v->sizeof_type);
	if (!data)
		return ;
	v->data = data;
	v->alloc_size = v->size;
}

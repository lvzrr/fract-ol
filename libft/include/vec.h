#ifndef VEC_H
# define VEC_H

# include <stddef.h>
# include "structs.h"
# include "mem.h"
# include "macros.h"

t_vec		ft_vec(size_t alloc_size, size_t sizeof_type);
void		ft_vec_push(t_vec *vec, void *data, size_t len);
void		ft_vec_free(t_vec *vec);
void		ft_vec_reserve(t_vec *v, size_t n);
void		ft_vec_pop(t_vec *__restrict__ v);
void		ft_vec_clear(t_vec *vec);
void		ft_vec_fit(t_vec *vec);
void		ft_vec_insert(t_vec *v, size_t index, void *data,
				size_t len);
void		*ft_vec_peek_last(t_vec *__restrict__ v);
t_u8		ft_vec_popmv(void *__restrict__ dst, t_vec *__restrict__ v);
void		ft_vec_rev(t_vec *v);
void		*ft_vec_get_mut(t_vec *vec, size_t idx);
void		*ft_vec_get_clone(t_vec *vec, size_t idx);
const void	*ft_vec_get(t_vec *vec, size_t idx);
#endif

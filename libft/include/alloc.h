#ifndef ALLOC_H
# define ALLOC_H

# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include <stdarg.h>
# include "mem.h"
# include "macros.h"
# include "structs.h"

# ifndef DEF_ALIGN
#  define DEF_ALIGN 128
# endif

# ifndef DEFAULT_ARENA_SIZE
#  define DEFAULT_ARENA_SIZE 262272
# endif

void			*ft_alloc(size_t size);
void			ft_free(void **ptr);
void			ft_free_array(void ***arr);
void			ft_defer(void *ptr);
void			ft_defer_arr(void ***ptr);
void			*ft_calloc(size_t n, size_t size);
void			*ft_extend(void *ptr, size_t n, size_t size);
void			*ft_extend_zero(void *ptr, size_t n, size_t size);
void			*ft_realloc(void *ptr, size_t n, size_t size);
void			*ft_recalloc(void *ptr, size_t n, size_t size);
void			*ft_arena(size_t size);
void			ft_free_arena(t_arena *arena);
#endif

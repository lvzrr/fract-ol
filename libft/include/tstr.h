#ifndef TSTR_H
# define TSTR_H
# include <sys/types.h>
# include <stdlib.h>
# include "structs.h"
# include "mem.h"
# include "alloc.h"
# include "cstr.h"

t_string		ft_tstr_from_cstr(const char *str);
char			*ft_tstr_dup_cstr(t_string *str);
t_string		ft_tstr_new(size_t len);
void			ft_tstr_pushstr(t_string *str, const char *s);
void			ft_tstr_push(t_string *str, char c);
void			ft_tstr_free(t_string *str);
const char		*ft_tstr_borrow(const t_string *str);
void			ft_tstr_clear(t_string *s);
void			ft_tstr_fit(t_string *str);
ssize_t			ft_tstr_instr(const t_string *h, const char *n);
void			ft_tstr_trim(t_string *str, const char *set);
t_string		ft_tstr_from_slice(char *s, size_t n);
void			ft_tstr_pushslice(t_string *str, const char *s, size_t n);
void			ft_tstr_reserve(t_string *str, size_t n);
char			ft_tstr_pop(t_string *str);
void			ft_tstr_repeat(t_string *str, const char *chunk,
					size_t times);
t_string		ft_tstr_clone(t_string *s);
#endif

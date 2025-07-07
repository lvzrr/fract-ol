#include "tstr.h"

void	ft_tstr_clear(t_string *s)
{
	if (!s || !s->data)
		return ;
	ft_memset(s->data, 0, s->len);
	s->len = 0;
}

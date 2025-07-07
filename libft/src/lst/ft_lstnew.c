#include "lft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newl;

	newl = (t_list *)ft_alloc(sizeof(t_list));
	if (!newl)
		return (NULL);
	newl->content = content;
	newl->next = NULL;
	return (newl);
}

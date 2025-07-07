#include "lft.h"

static void	*errorhandle(t_list *newl, void *tmp, void (*del)(void *))
{
	del(tmp);
	ft_lstclear(&newl, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*tmp;
	t_list	*newl;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	newl = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		newnode = ft_lstnew(tmp);
		if (!newnode)
			return (errorhandle(newl, tmp, del));
		ft_lstadd_back(&newl, newnode);
		lst = lst->next;
	}
	return (newl);
}

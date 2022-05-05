#include "push_swap.h"

t_list	*ft_lstnew_int(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
}

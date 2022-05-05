#include "push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (!(*alst))
	{
		(*alst) = new;
		return ;
	}
	begin = (*alst);
	while (begin->next)
		begin = begin->next;
	begin->next = new;
}

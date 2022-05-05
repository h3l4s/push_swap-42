#include "push_swap.h"

int	error_main(void)
{
	printf("Error\n");
	return (1);
}

void	ft_swap_first(t_list **alst, int num)
{
	t_list	*temp;
	t_list	*temp2;

	if (num == 2)
		printf("sb\n");
	if (num == 1)
		printf("sa\n");
	if ((*alst)->next)
	{
		temp = *alst;
		(*alst) = (*alst)->next;
		temp2 = (*alst)->next;
		(*alst)->next = temp;
		temp->next = temp2;
	}
}

void	ft_push(t_list **alst, t_list **new, int which)
{
	t_list	*temp;

	if (which == 2)
		printf("pb\n");
	if (which == 1)
		printf("pa\n");
	if ((*new) == NULL)
	{
		(*new) = (*alst);
		(*alst) = (*alst)->next;
		(*new)->next = NULL;
		return ;
	}
	else if ((*new)->number == -5)
	{
		free((*new));
		(*new) = (*alst);
		(*alst) = (*alst)->next;
		(*new)->next = NULL;
		return ;
	}
	temp = (*alst);
	(*alst) = (*alst)->next;
	temp->next = (*new);
	(*new) = temp;
}

void	ft_rotate(t_list **alst, int which)
{
	t_list	*temp;
	t_list	*temp2;

	if (which == 1)
		printf("ra\n");
	if (which == 2)
		printf("rb\n");
	temp = (*alst);
	temp2 = (*alst)->next;
	if ((*alst)->next == NULL)
		return ;
	while ((*alst)->next)
		(*alst) = (*alst)->next;
	(*alst)->next = temp;
	temp->next = NULL;
	if (temp2)
		(*alst) = temp2;
}

void	ft_reverse_rotate(t_list **alst, int num)
{
	t_list	*temp2;
	t_list	*temp;
	t_list	*temp3;

	if (num == 1)
		printf("rra\n");
	if (num == 2)
		printf("rrb\n");
	temp3 = (*alst);
	temp = (*alst)->next;
	while ((*alst)->next->next)
		(*alst) = (*alst)->next;
	temp2 = (*alst)->next;
	(*alst)->next = NULL;
	temp2->next = temp3;
	temp3->next = temp;
	(*alst) = temp2;
}

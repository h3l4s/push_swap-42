#include "push_swap.h"

void	ft_sort_three(t_list **a_list)
{
	if ((*a_list)->number > (*a_list)->next->number
		&& (*a_list)->next->number > (*a_list)->next->next->number)
	{
		ft_swap_first(a_list, 1);
		ft_reverse_rotate(a_list, 1);
	}
	else if ((*a_list)->number > (*a_list)->next->number
		&& (*a_list)->next->number < (*a_list)->next->next->number)
	{
		if ((*a_list)->number < (*a_list)->next->next->number)
			ft_swap_first(a_list, 1);
		else
			ft_rotate(a_list, 1);
	}
	else if ((*a_list)->number < (*a_list)->next->number
		&& (*a_list)->next->number > (*a_list)->next->next->number)
	{
		if ((*a_list)->number < (*a_list)->next->next->number)
		{
			ft_swap_first(a_list, 1);
			ft_rotate(a_list, 1);
		}
		else
			ft_reverse_rotate(a_list, 1);
	}
}

int	cut_ft_check(char **argv, int i)
{
	if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
		return (1);
	if (temp_strlen(argv[i]) > 10)
		return (1);
	return (0);
}

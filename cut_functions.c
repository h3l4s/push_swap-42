#include "push_swap.h"

void	cut_sort(t_list **a_list, int num, t_list **b_list)
{
	int	numero;

	numero = (*a_list)->number;
	numero = make_decimal(numero);
	if (((numero >> num) & 1))
		ft_rotate(a_list, 1);
	else
		ft_push(a_list, b_list, 2);
}

void	cut_sort_five(t_list **a_list, t_list **b_list)
{
	while ((*a_list)->number != 0)
	{
		if ((*a_list)->next->number == 0 || (*a_list)->next->next->number == 0)
			ft_rotate(a_list, 1);
		else
			ft_reverse_rotate(a_list, 1);
	}
	ft_push(a_list, b_list, 2);
	while ((*a_list)->number != 1)
	{
		if ((*a_list)->next->number == 1 || (*a_list)->next->next->number == 1)
			ft_rotate(a_list, 1);
		else
			ft_reverse_rotate(a_list, 1);
	}
	ft_push(a_list, b_list, 2);
}

int	*cut_make_tab(int i, int argc, int *tab)
{
	int	chang;
	int	temp;

	chang = 1;
	while (chang == 1)
	{
		chang = 0;
		i = 0;
		while (i < argc - 2)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				chang = 1;
			}
			i++;
		}
	}
	return (tab);
}

int	cut_main(int *stock, t_list **a_list, int *tab, char **argv)
{
	int	i2;

	i2 = -1;
	while (++i2 < stock[1] - 1)
	{
		if (tab[i2] == ft_atoi(argv[stock[0]]))
		{
			if (stock[2] == 0)
			{
				if (stock[1] != 6)
					(*a_list) = ft_lstnew_int(make_binary(i2));
				else
					(*a_list) = ft_lstnew_int(i2);
				stock[2] = 1;
			}
			else
			{
				if (stock[1] != 6)
					ft_lstadd_back(a_list, ft_lstnew_int(make_binary(i2)));
				else
					ft_lstadd_back(a_list, ft_lstnew_int(i2));
			}
		}
	}
	return (stock[2]);
}

void	free_list(t_list **a_list, int *tab)
{
	t_list	*temp;

	free(tab);
	while ((*a_list)->next)
	{
		temp = (*a_list);
		(*a_list) = (*a_list)->next;
		free(temp);
	}
	free(*a_list);
}

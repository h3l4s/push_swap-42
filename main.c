#include "push_swap.h"

int	top_list(t_list **lst)
{
	int		i;
	t_list	*temp;
	int		i2;

	i2 = 0;
	temp = (*lst);
	i = temp->number;
	while (temp->next)
	{
		if (temp->number > i)
			i = temp->number;
		temp = temp->next;
	}
	while (i / 10)
	{
		i = i / 10;
		i2++;
	}
	i2 += 1;
	return (i2);
}

void	ft_sort_linked(t_list **a_list, int argc)
{
	t_list	*b_list;
	int		i;
	int		max_bit;
	int		num;

	i = 0;
	num = 0;
	b_list = ft_lstnew_int(-5);
	max_bit = top_list(a_list);
	while (num < max_bit)
	{
		while (i < argc - 1)
		{
			cut_sort(a_list, num, &b_list);
			i++;
		}
		while (b_list)
			ft_push(&b_list, a_list, 1);
		i = 0;
		num++;
	}
	i = 0;
	free(b_list);
}

void	ft_sort_five(t_list **a_list)
{
	t_list	*b_list;

	b_list = ft_lstnew_int(-5);
	cut_sort_five(a_list, &b_list);
	while ((*a_list)->number != 2)
	{
		if ((*a_list)->next->number == 2)
			ft_rotate(a_list, 1);
		else
			ft_reverse_rotate(a_list, 1);
	}
	ft_push(a_list, &b_list, 2);
	if ((*a_list)->number > (*a_list)->next->number)
		ft_rotate(a_list, 1);
	ft_push(&b_list, a_list, 1);
	ft_push(&b_list, a_list, 1);
	ft_push(&b_list, a_list, 1);
}

int	*ft_make_tab(char **argv, int argc)
{
	int	i;
	int	*tab;
	int	i3;

	i = 0;
	while (argv[i])
		i++;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (0);
	i = 0;
	i3 = 1;
	while (argv[i3])
	{
		tab[i] = ft_atoi(argv[i3]);
		i++;
		i3++;
	}
	tab = cut_make_tab(i, argc, tab);
	return (tab);
}

int	main(int argc, char **argv)
{
	t_list	*a_list;
	int		stock[3];
	int		*tab;

	stock[0] = 0;
	stock[1] = argc;
	stock[2] = ft_check(argv);
	if (stock[2] == 1)
		return (error_main());
	if (ft_check_sorted(argv, argc))
		return (0);
	tab = ft_make_tab(argv, argc);
	stock[2] = 0;
	while (++stock[0] < argc)
		stock[2] = cut_main(stock, &a_list, tab, argv);
	if (argc == 6)
		ft_sort_five(&a_list);
	else if (argc == 4)
		ft_sort_three(&a_list);
	else
		ft_sort_linked(&a_list, argc);
	free_list(&a_list, tab);
	return (0);
}

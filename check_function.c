#include "push_swap.h"

int	temp_strlen(char *s)
{
	int	i;
	int	neg;

	if (ft_atoi(s) > 2147483647 || ft_atoi(s) < -2147483648)
		return (11);
	i = 0;
	neg = 0;
	if (s[i] == '-')
	{
		i++;
		neg = 1;
	}
	while (s[i])
		i++;
	if (neg == 1)
		return (i - 1);
	return (i);
}

int	check_digit(int num, int max)
{
	int	total;

	total = 0;
	while (max)
	{
		total = total * 10;
	}
	while (num != 0 && num != 1)
	{
		num = num % 10;
	}
	return (num);
}

int	check_list(t_list *a_list)
{
	while (a_list)
	{
		if (a_list->number > a_list->next->number)
			return (1);
		a_list = a_list->next;
	}
	return (0);
}

int	ft_check(char **argv)
{
	int	i;
	int	i2[2];
	int	tab[1000];

	i = 1;
	i2[0] = 0;
	i2[1] = 1;
	if (!argv[1])
		return (0);
	if (cut_ft_check(argv, 1))
		return (1);
	while (argv[i])
	{
		while (i2[1] < i2[0])
		{
			if (ft_atoi(argv[i]) == tab[i2[1]] || cut_ft_check(argv, i))
				return (1);
			i2[1]++;
		}
		tab[i2[0]] = ft_atoi(argv[i]);
		i++;
		i2[0]++;
		i2[1] = 0;
	}
	return (0);
}

int	ft_check_sorted(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

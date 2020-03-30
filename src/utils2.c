#include "../inc/push_swap.h"

int		get_max_index(t_stack stack)
{
	int max;
	int max_index;
	int i;

	max = stack.tab[stack.begin];
	max_index = stack.begin;
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] > max)
		{
			max = stack.tab[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int		get_min_index(t_stack stack)
{
	int min;
	int min_index;
	int i;

	min = stack.tab[stack.begin];
	min_index = stack.begin;
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] < min)
		{
			min = stack.tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int		ft_free_and_return(t_struct *ps)
{
	if (ps->stack_a.tab)
	{
		free(ps->stack_a.tab);
		ps->stack_a.tab = NULL;
	}
	if (ps->stack_b.tab)
	{
		free(ps->stack_b.tab);
		ps->stack_b.tab = NULL;
	}
	return (0);
}
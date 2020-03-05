#include "../inc/push_swap.h"

int	check_order(t_stack stack_a)
{
	int i;

	i = stack_a.begin;
	if (i != 0)
		return (0);
	while (i < stack_a.size - 1)
	{
		if (stack_a.tab[i] < stack_a.tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
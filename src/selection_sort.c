#include "../inc/push_swap.h"

void	selection_sort(t_struct *ps, void (*f[4])(t_struct *ps, int instr_nb, char write_it))
{
	int unsorted_index;
	int i;
	int *minimum;
	int *found;

	unsorted_index = 0;
	while (unsorted_index < ps->stack_a.size)
	{
		i = unsorted_index;
		minimum = &ps->stack_a.tab[unsorted_index];
		found = minimum;
		while (i < ps->stack_a.size)
		{
			if (ps->stack_a.tab[i] < *found)
				found = &ps->stack_a.tab[i];
			i++;
		}
		if (*found != *minimum)
		{
			move_to_top(ps, found);
			f[get_ft_nb(PB)](ps, PB, 1);
		}
		unsorted_index++;
	}
	while (!is_stack_empty(ps->stack_b))
			f[get_ft_nb(PB)](ps, PA, 1);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
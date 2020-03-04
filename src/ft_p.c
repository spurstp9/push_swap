#include "../inc/push_swap.h"

void	ft_p(t_struct *ps, int instr_nb)
{
	if (instr_nb == PA)
		apply_p(ps->stack_a, ps->stack_b);
	apply_p(ps->stack_b, ps->stack_a);
}

void	apply_p(t_stack dest, t_stack source)
{
	if (source.size - source.begin > -1)
	{
		dest.begin--;
		dest.tab[dest.begin] = source.tab[source.begin];
		source.begin++;
	}
}
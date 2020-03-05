#include "../inc/push_swap.h"

void	ft_r(t_struct *ps, int instr_nb)
{
	if (instr_nb == RA || instr_nb == RR)
		apply_r(&ps->stack_a);
	if (instr_nb == RB || instr_nb == RR)
		apply_r(&ps->stack_b);
}

void	apply_r(t_stack *stack)
{
	int i;
	int top;

	i = stack->begin;
	top = stack->tab[i];
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		stack->tab[i + 1] = top;
		i++;
	}
}
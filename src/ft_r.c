#include "../inc/push_swap.h"

void	ft_r(t_struct *ps, int instr_nb)
{
	if (instr_nb == RA || instr_nb == RR)
		apply_r(ps->stack_a);
	if (instr_nb == RB || instr_nb == RR)
		apply_r(ps->stack_b);
}

void	apply_r(t_stack stack)
{
	int i;
	int top;

	i = stack.begin;
	top = stack[i];
	while (i < stack.end)
	{
		stack[i] = stack[i + 1];
		stack[i + 1] = top;
		i++;
	}
}
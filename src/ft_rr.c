#include "../inc/push_swap.h"

void	ft_rr(t_struct *ps, int instr_nb, char write_it)
{
	if (instr_nb == RRA || instr_nb == RRR)
		apply_rr(&ps->stack_a);
	if (instr_nb == RRB || instr_nb == RRR)
		apply_rr(&ps->stack_b);
	if (write_it)
	{
		if (instr_nb == RRA)
			write(1, "rra\n", 4);
		else if (instr_nb == RRB)
			write(1, "rrb\n", 4);
		else if (instr_nb == RRR)
			write(1, "rrr\n", 4);
	}
}

void	apply_rr(t_stack *stack)
{
	int i;
	int bottom;

	i = stack->size - 1;
	bottom = stack->tab[i];
	while (stack->begin < i)
	{
		stack->tab[i] = stack->tab[i - 1];
		stack->tab[i - 1] = bottom;
		i--;
	}
}
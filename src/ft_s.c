#include "../inc/push_swap.h"

void	ft_s(t_struct *ps, int instr_nb)
{
	if (instr_nb == SA || instr_nb == SS)
		apply_s(&ps->stack_a);
	if (instr_nb == SB || instr_nb == SS)
		apply_s(&ps->stack_b);
}

void	apply_s(t_stack *stack)
{
	int tmp;

	if (1 <= stack->size - stack->begin)
	{
		tmp = stack->tab[stack->begin];
		stack->tab[stack->begin] = stack->tab[stack->begin + 1];
		stack->tab[stack->begin + 1] = tmp;
	}
}
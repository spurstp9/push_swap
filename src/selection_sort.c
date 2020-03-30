#include "../inc/push_swap.h"

void	selection_sort(t_struct *ps)
{
	int min;
	int min_index;
	int middle;
	int instr;

	min = get_min(ps->stack_a);
	min_index = get_min_index(ps->stack_a);
	middle = (ps->stack_a.size - ps->stack_a.begin) / 2 + ps->stack_a.begin;
	instr = (min_index <= middle ? RA : RRA);
	while (ps->stack_a.tab[ps->stack_a.begin] != min)
		apply_instr(ps, instr, 1);
	if (!check_order(ps->stack_a))
		apply_instr(ps, PB, 1);
}
#include "../inc/push_swap.h"

void	deal_with_five(t_struct *ps)
{
	int first;
	int last;

	while (ps->stack_a.size - 1 - ps->stack_a.begin != 2)
		apply_instr(ps, PB, 1);
	deal_with_three(ps);
	while (ps->stack_a.begin != 0)
	{
		first = ps->stack_a.tab[ps->stack_a.begin];
		last = ps->stack_a.tab[ps->stack_a.size - 1];
		if (ps->stack_b.tab[ps->stack_b.begin] > last)
		{
			apply_instr(ps, PA, 1);
			apply_instr(ps, RA, 1);
		}
		else if (ps->stack_b.tab[ps->stack_b.begin] < first)
			apply_instr(ps, PA, 1);
		else
			selection_sort_five(ps);
	}
}

void	selection_sort_five(t_struct *ps)
{
	int rank;
	int i;
	int instr;
	int middle;

	rank = get_bigger_number_rank(ps);
	middle = (ps->stack_a.size - ps->stack_a.begin) / 2 + ps->stack_a.begin;
	instr = (rank <= middle ? RA : RRA);
	rank = (instr == RA ? rank - ps->stack_a.begin : ps->stack_a.size - rank);
	i = rank;
	while (rank--)
		apply_instr(ps, instr, 1);
	apply_instr(ps, PA, 1);
	instr = (instr == RA ? RRA : RA);
	while (i--)
		apply_instr(ps, instr, 1);
	if (instr == RA)
		apply_instr(ps, instr, 1);
}

int		get_bigger_number_rank(t_struct *ps)
{
	int i;
	int rank;

	rank = 0;
	i = ps->stack_a.begin + 1;
	while (i < ps->stack_a.size)
	{
		if (ps->stack_b.tab[ps->stack_b.begin] < ps->stack_a.tab[i])
		{
			rank = i;
			break ;
		}
		else
			i++;
	}
	return (rank);
}
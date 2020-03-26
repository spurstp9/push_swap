#include "../inc/push_swap.h"

void	deal_with_five(t_struct *ps, void (*f[4])(t_struct *ps, int instr_nb, char write_it))
{
	int first;
	int last;

	while (ps->stack_a.size - 1 - ps->stack_a.begin != 2)
		f[get_ft_nb(PB)](ps, PB, 1);
	deal_with_three(ps, f);
	// print_stack_a(ps);
	while (ps->stack_a.begin != 0)
	{
		first = ps->stack_a.tab[ps->stack_a.begin];
		last = ps->stack_a.tab[ps->stack_a.size - 1];
		if (ps->stack_b.tab[ps->stack_b.begin] > last)
		{
			f[get_ft_nb(PA)](ps, PA, 1);
			f[get_ft_nb(RA)](ps, RA, 1);
		}
		else if (ps->stack_b.tab[ps->stack_b.begin] < first)
			f[get_ft_nb(PA)](ps, PA, 1);
		else
			selection_sort_five(ps, f);
		// print_stack_a(ps);
	}
}

void	selection_sort_five(t_struct *ps, void (*f[4])(t_struct *ps, int instr_nb, char write_it))
{
	int rank;
	int i;
	int instr;
	int middle;

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
	// printf("rank = %d\n", rank);
	middle = (ps->stack_a.size - ps->stack_a.begin) / 2 + ps->stack_a.begin;
	// printf("middle = %d\n", middle);
	instr = (rank <= middle ? RA : RRA);
	rank = (instr == RA ? rank - ps->stack_a.begin : ps->stack_a.size - rank);
	i = rank;
	while (rank--)
		f[get_ft_nb(instr)](ps, instr, 1);
	f[get_ft_nb(PA)](ps, PA, 1);
	instr = (instr == RA ? RRA : RA);
	while (i--)
		f[get_ft_nb(instr)](ps, instr, 1);
	if (instr == RA)
		f[get_ft_nb(instr)](ps, instr, 1);
}
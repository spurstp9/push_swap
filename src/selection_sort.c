#include "../inc/push_swap.h"

void	selection_sort(t_struct *ps, void (*f[4])(t_struct *ps, int instr_nb, char write_it))
{
	int min;
	int min_index;
	int middle;
	int instr;

	// print_stack_a(ps);
	min = get_min(ps->stack_a);
	min_index = get_min_index(ps->stack_a);
	middle = (ps->stack_a.size - ps->stack_a.begin) / 2 + ps->stack_a.begin;
	// printf("begin = %d min_index = %d middle = %d min = %d\n", ps->stack_a.begin, min_index, middle, min);
	instr = (min_index <= middle ? RA : RRA);
	while (ps->stack_a.tab[ps->stack_a.begin] != min)
		f[get_ft_nb(instr)](ps, instr, 1);
	if (!check_order(ps->stack_a))
		f[get_ft_nb(PB)](ps, PB, 1);
}
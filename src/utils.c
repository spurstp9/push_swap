#include "../inc/push_swap.h"

void			ft_init(t_struct *ps)
{
	ps->stack_a.tab = NULL;
	ps->stack_a.begin = 0;
	ps->stack_a.size = 0;
	ps->stack_b.tab = NULL;
	ps->stack_b.begin = 0;
	ps->stack_b.size = 0;
	ps->instr_stock.tab = NULL;
	ps->instr_stock.begin = 0;
	ps->instr_stock.size = 0;
}

void			print_stack_a(t_struct *ps)
{
	int i;

	i = ps->stack_a.begin;
	printf("begin = %d\n", i);
	printf("\n\nprint_stack_a size = %d\n", ps->stack_a.size);
	while (i < ps->stack_a.size)
	{
		printf("%d\n", (ps->stack_a.tab)[i]);
		i++;
	}
	printf("\n");
}

void			print_stack_b(t_struct *ps)
{
	int i;

	i = ps->stack_b.begin;
	printf("begin = %d\n", i);
	printf("\n\nprint_stack_b size = %d\n", ps->stack_b.size);
	while (i < ps->stack_b.size)
	{
		printf("%d\n", (ps->stack_b.tab)[i]);
		i++;
	}
	printf("\n");
}
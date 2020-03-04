#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_struct	ps;

	if (argc == 1)
	{
		// while (1)
		// 	;
		return (0);
	}
	ft_init(&ps);
	if (!check_args(argc, argv, &ps) || !check_instr(&ps))
	{
		write(2, "Error\n", 6);
		free(ps.stack_a.tab);
		// while (1)
		// 	;
		return (0);
	}
	// print_stack_a(&ps);
	if (!(ps.stack_b.tab = (int*)malloc(sizeof(int) * ps.stack_a.size)))
		return (0);
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
	ps.stack_b.size = ps.stack_a.size;
	apply_instr(&ps);
	free(ps.stack_a.tab);
	ps.stack_a.tab = NULL;
	free(ps.stack_b.tab);
	ps.stack_b.tab = NULL;
	free(ps.instr_stock.tab);
	ps.instr_stock.tab = NULL;
	// free(line);
	// line = NULL;
	// while (1)
	// 	;
	return (0);
}

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

	i = 0;
	printf("\n\nprint_stack_a\n");
	while (i < ps->stack_a.size)
	{
		printf("%d\n", (ps->stack_a.tab)[i]);
		i++;
	}
}

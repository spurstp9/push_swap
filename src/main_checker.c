#include "../inc/push_swap.h"

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
	ps.stack_b.begin = ps.stack_b.size;
	apply_instr(&ps, 0);
	// print_stack_a(&ps);
	// print_stack_b(&ps);
	if (!check_order(ps.stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
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
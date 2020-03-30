#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	ps;

	if (argc == 1)
		return (0);
	ft_init(&ps);
	if (!check_args(argc, argv, &ps))
	{
		write(2, "Error\n", 6);
		return (ft_free_and_return(&ps));
	}
	if (!(ps.stack_b.tab = (int*)malloc(sizeof(int) * ps.stack_a.size)))
		return (ft_free_and_return(&ps));
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
	ps.stack_b.size = ps.stack_a.size;
	ps.stack_b.begin = ps.stack_b.size;
	if (!check_instr(&ps))
	{
		write(2, "Error\n", 6);
		return (ft_free_and_return(&ps));
	}
	if (!check_order(ps.stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return(ft_free_and_return(&ps));
}
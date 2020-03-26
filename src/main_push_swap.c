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
		free(ps.stack_a.tab);
		return (0);
	}
	if (!(ps.stack_b.tab = (int*)malloc(sizeof(int) * ps.stack_a.size)))
		return (0);
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
	ps.stack_b.size = ps.stack_a.size;
	ps.stack_b.begin = ps.stack_b.size;
	if (!check_order(ps.stack_a))
		find_instr(&ps);
	free(ps.stack_a.tab);
	ps.stack_a.tab = NULL;
	free(ps.stack_b.tab);
	ps.stack_b.tab = NULL;
	return (0);
}

void	find_instr(t_struct *ps)
{
	static void (*f[4])(t_struct *ps, int instr_nb, char write_it) = {&ft_s, &ft_p, &ft_r, &ft_rr};

	if (ps->stack_a.size == 3)
		deal_with_three(ps, f);
	else if (ps->stack_a.size <= 5)
		deal_with_five(ps, f);
	else if (ps->stack_a.size <= 20)
	{
		if (ps->stack_a.tab[0] > ps->stack_a.tab[1])
			f[get_ft_nb(SA)](ps, SA, 1);
		while (ps->stack_a.begin < ps->stack_a.size - 1 && !check_order(ps->stack_a))
			selection_sort(ps, f);
		// printf("begin = %d\n", ps->stack_a.begin);
		while (!is_stack_empty(&ps->stack_b))
			f[get_ft_nb(PA)](ps, PA, 1);
		// sort_algo_loop(ps, 2, f);
	}
	else if (ps->stack_a.size < 500)
		sort_algo_loop(ps, 5, f);
	else
		sort_algo_loop(ps, 11, f);
	// print_stack_a(ps);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:04:49 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:05:00 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/prototypes.h"

int		main(int argc, char **argv)
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
	if (!check_order(ps.stack_a))
		find_instr(&ps);
	ft_free_and_return(&ps);
	return (0);
}

void	find_instr(t_struct *ps)
{
	if (stack_size(&ps->stack_a) <= 20)
	{
		while (stack_size(&ps->stack_a) > 3
			&& !check_order(ps->stack_a))
			selection_sort(ps);
		if (stack_size(&ps->stack_a) <= 3)
			sort_last_three(ps);
		while (!is_stack_empty(&ps->stack_b))
			apply_instr(ps, PA, 1);
	}
	else if (ps->stack_a.size < 500)
		sort_algo_loop(ps, 5);
	else
		sort_algo_loop(ps, 11);
}

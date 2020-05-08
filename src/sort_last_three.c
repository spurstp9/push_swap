/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:02:55 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:02:50 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/prototypes.h"

void	sort_last_three(t_struct *ps)
{
	int first;
	int second;
	int third;

	if (ps->stack_a.begin == ps->stack_a.size - 2)
	{
		if (!check_order(ps->stack_a))
			apply_instr(ps, SA, 1);
		return ;
	}
	first = ps->stack_a.tab[ps->stack_a.begin];
	second = ps->stack_a.tab[ps->stack_a.begin + 1];
	third = ps->stack_a.tab[ps->stack_a.begin + 2];
	if (first > second && second < third && first < third)
		apply_instr(ps, SA, 1);
	else if (first > second && second > third && first > third)
	{
		apply_instr(ps, SA, 1);
		apply_instr(ps, RRA, 1);
	}
	else if (first > second && second < third && first > third)
		apply_instr(ps, RA, 1);
	else if (first < second && second > third && first < third)
	{
		apply_instr(ps, SA, 1);
		apply_instr(ps, RA, 1);
	}
	else if (first < second && second > third && first > third)
		apply_instr(ps, RRA, 1);
}

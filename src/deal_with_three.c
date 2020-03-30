/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina </var/mail/agardina>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:02:55 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 17:03:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	deal_with_three(t_struct *ps)
{
	int first;
	int second;
	int third;

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

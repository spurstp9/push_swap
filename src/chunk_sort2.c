#include "../inc/push_swap.h"

int		get_rank(t_stack stack, t_chunk ch, char up_or_down)
{
	int i;

	if (!up_or_down)
	{
		i = stack.begin;
		while (i < stack.size && !(ch.chunk_min <= stack.tab[i]
			&& stack.tab[i] <= ch.chunk_max))
			i++;
	}
	else
	{
		i = stack.size - 1;
		while (stack.begin <= i && !(ch.chunk_min <= stack.tab[i]
			&& stack.tab[i] <= ch.chunk_max))
			i--;
	}
	if (i == stack.size || i == stack.begin - 1)
		return (-1);
	return (i);
}

void	ft_move_to_b(t_struct *ps, int rank, int instr)
{
	int nb;
	int min_b;

	nb = ps->stack_a.tab[rank];
	while (ps->stack_a.tab[ps->stack_a.begin] != nb)
	apply_instr(ps, instr, 1);
	apply_instr(ps, PB, 1);
	min_b = get_min(ps->stack_b);
	if (nb < min_b)
		apply_instr(ps, RB, 1);
	if (ps->stack_b.begin < ps->stack_b.size - 1 && nb < ps->stack_b.tab[ps->stack_b.begin + 1])
		apply_instr(ps, SB, 1);
}

void	ft_move_back_to_a(t_struct *ps)
{
	int max;
	int max_index;
	int middle;
	int instr;

	max = get_max(ps->stack_b);
	max_index = get_max_index(ps->stack_b);
	middle = (ps->stack_b.size - ps->stack_b.begin) / 2 + ps->stack_b.begin;
	instr = (max_index <= middle ? RB : RRB);
	max_index = 0;
	while (ps->stack_b.tab[ps->stack_b.begin] != max && ++max_index)
	apply_instr(ps, instr, 1);
	apply_instr(ps, PA, 1);
}

void	init_chunk(t_struct *ps, t_chunk *ch, int nb)
{
	ch->stack_min = get_min(ps->stack_a);
	ch->stack_max = get_max(ps->stack_a);
	ch->chunk_min = ch->stack_min;
	ch->interval = (ch->stack_max - ch->stack_min) / nb;
	ch->chunk_max = ch->stack_min + ch->interval;
	ch->chunk_nb = 1;
}
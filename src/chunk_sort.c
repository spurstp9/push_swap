#include "../inc/push_swap.h"


void	sort_algo_loop(t_struct *ps, int nb)
{
	t_chunk ch;

	// print_stack_a(ps);
	init_chunk(ps, &ch, nb);
	// printf("Chunk %d : %d - %d\n", ch.chunk_nb, ch.chunk_min, ch.chunk_max);
	while (ps->stack_a.begin < ps->stack_a.size)
	{
		// printf("begin = %d\n", ps->stack_a.begin);
		sort_algo(ps, &ch, nb);
		// printf("\nSort ok\n\n");
	}
	// print_stack_b(ps);
	while (!is_stack_empty(&ps->stack_b))
		ft_move_back_to_a(ps);
}

int	sort_algo(t_struct *ps, t_chunk *ch, int nb)
{
	int rank_up;
	int rank_down;
	int rank_to_move;
	int instr;

	if ((rank_up = get_rank(ps->stack_a, *ch, 0)) < 0)
	{
		// printf("Oh\n");
		// print_stack_a(ps);
		ch->chunk_min = ch->chunk_max + 1;
		ch->chunk_max = ch->chunk_min + ch->interval - 1;
		ch->chunk_nb++;
		if (ch->chunk_nb == nb && ch->chunk_max < ch->stack_max)
			ch->chunk_max = ch->stack_max;
		// printf("Chunk %d : %d - %d\n", ch->chunk_nb, ch->chunk_min, ch->chunk_max);
		return (sort_algo(ps, ch, nb));
	}
	// printf("Chunk %d : %d - %d\n", ch->chunk_nb, ch->chunk_min, ch->chunk_max);
	rank_down = get_rank(ps->stack_a, *ch, 1);
	// printf("rank_up = %d rank_down = %d", rank_up, rank_down);
	// if (rank_up - ps->stack_a.begin == ps->stack_a.size - rank_down)
	// 	rank_to_move = ps->stack_a.tab[rank_up] > ps->stack_a.tab[rank_down] ? rank_up : rank_down;
	// else
		rank_to_move = (rank_up - ps->stack_a.begin < ps->stack_a.size - rank_down ? rank_up : rank_down);
	instr = (rank_to_move - ps->stack_a.begin < ps->stack_a.size - rank_to_move ? RA : RRA);
	ft_move_to_b(ps, rank_to_move, instr);
	return (0);
}

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
	// printf("NOMBRE A METTRE DANS LA PILE B : %d\n", nb);
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
	// instr = (instr == RB ? RRB : RB);
	// while (max_index--)
	// 	f[get_ft_nb(instr)](ps, instr, 1);
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
#include "../inc/push_swap.h"

void			ft_init(t_struct *ps)
{
	ps->stack_a.tab = NULL;
	ps->stack_a.begin = 0;
	ps->stack_a.size = 0;
	ps->stack_b.tab = NULL;
	ps->stack_b.begin = 0;
	ps->stack_b.size = 0;
}

void			print_stack_a(t_struct *ps)
{
	int i;

	i = ps->stack_a.begin;
	// printf("begin = %d\n", i);
	// printf("\n\nprint_stack_a size = %d\n", ps->stack_a.size);
	while (i < ps->stack_a.size)
	{
		printf("[%d] %d\n", i, (ps->stack_a.tab)[i]);
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

int				is_stack_empty(t_stack *stack)
{
	if (stack->begin == stack->size)
		return (1);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		get_max(t_stack stack)
{
	int max;
	int i;

	max = stack.tab[stack.begin];
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] > max)
			max = stack.tab[i];
		i++;
	}
	return (max);
}

int		get_min(t_stack stack)
{
	int min;
	int i;

	min = stack.tab[stack.begin];
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] < min)
			min = stack.tab[i];
		i++;
	}
	return (min);
}

int		get_max_index(t_stack stack)
{
	int max;
	int max_index;
	int i;

	max = stack.tab[stack.begin];
	max_index = stack.begin;
	// printf("indice de départ = %d nd de départ = %d\n", max_index, max);
	i = stack.begin + 1;
	while (i < stack.size)
	{
		// printf("nombre à tester : %d ", stack.tab[i]);
		if (stack.tab[i] > max)
		{
			// printf("plus petit que %d, indice = %d\n", max, i);
			max = stack.tab[i];
			max_index = i;
		}
		i++;
	}
	// printf("\nmax_index trouvé : %d\n\n", max_index);
	return (max_index);
}

int		get_min_index(t_stack stack)
{
	int min;
	int min_index;
	int i;

	min = stack.tab[stack.begin];
	min_index = stack.begin;
	// printf("indice de départ = %d nd de départ = %d\n", min_index, min);
	i = stack.begin + 1;
	while (i < stack.size)
	{
		// printf("nombre à tester : %d ", stack.tab[i]);
		if (stack.tab[i] < min)
		{
			// printf("plus petit que %d, indice = %d\n", min, i);
			min = stack.tab[i];
			min_index = i;
		}
		i++;
	}
	// printf("\nmin_index trouvé : %d\n\n", min_index);
	return (min_index);
}
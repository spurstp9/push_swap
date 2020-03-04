#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_struct	ps;
	int			*instr_stock;

	ps.size = 0;
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	instr_stock = NULL;
	if (argc == 1)
	{
		// while (1)
		// 	;
		return (0);
	}
	if (!check_args(argc, argv, &ps) || !check_instr(instr_stock))
	{
		write(2, "Error\n", 6);
		free(ps.stack_a);
		// while (1)
		// 	;
		return (0);
	}
	// print_stack_a(&ps);
	if (!(ps.stack_b = (int*)malloc(sizeof(int) * ps.size)))
		return (0);
	ft_bzero(ps.stack_b, ps.size * sizeof(int));
	free(ps.stack_a);
	ps.stack_a = NULL;
	free(ps.stack_b);
	ps.stack_b = NULL;
	// free(line);
	// line = NULL;
	// while (1)
	// 	;
	return (0);
}

int				check_args(int argc, char **argv, t_struct *ps)
{
	int i;
	int	nb;

	i = 1;
	nb = 0;
	while (i < argc)
	{
		if (!check_line(ps, argv[i], &nb))
		{
			free(ps->stack_a);
			ps->stack_a = NULL;
			return (0);
		}
		if (!ft_realloc(&(ps->stack_a), ++ps->size, nb))
			return (0);
		i++;
	}
	return (1);
}

int				check_instr(int *instr_stock)
{
	int			i;
	int			size;
	char		*line;
	static char	*instr[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	line = NULL;
	size = 0;
	while (get_next_line(1, &line) == 1)
	{
		i = 0;
		while (i < 11 && ft_strcmp(line, instr[i]))
			i++;
		free(line);
		line = NULL;
		if (i == 11)
			return (0);
		if (!ft_realloc(&instr_stock, ++size, i))
			return (0);
	}
	i = 0;
	// while (i < size)
	// {
	// 	printf("%s\n", instr[instr_stock[i]]);
	// 	i++;
	// }
	return (1);
}

int				ft_realloc(int **tab, int size, int to_add)
{
	int			*tmp;

	tmp = NULL;
	if (!(tmp = (int*)malloc(sizeof(int) * size)))
		return (0);
	if (*tab)
		ft_memcpy(tmp, *tab, size * sizeof(int));
	free(*tab);
	tmp[size - 1] = to_add;
	*tab = tmp;
	return (1);
}

int				check_line(t_struct *ps, char *arg, int *nb)
{
	int i;

	i = 0;
	if (!arg[0])
		return (0);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+')
			i++;
		else
			return (0);
	}
	*nb = ft_atoi(arg);
	if ((arg[0] == '-' && *nb > 0) 
			|| ((arg[0] == '+' || ft_isdigit(arg[0])) && *nb < 0))
		return (0);
	i = 0;
	while (i < ps->size)
	{
		if (*nb != (ps->stack_a)[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void			print_stack_a(t_struct *ps)
{
	int i;

	i = 0;
	printf("\n\nprint_stack_a\n");
	while (i < ps->size)
	{
		printf("%d\n", (ps->stack_a)[i]);
		i++;
	}
}

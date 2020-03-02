#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char		*line;
	t_struct	ps;
	int			*tmp;
	int		nb;

	(void)argc;
	(void)argv;
	line = NULL;
	tmp = NULL;
	ps.size = 0;
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	while (get_next_line(1, &line) == 1)
	{
		if (!check_line(line))
		{
			free(ps.stack_a);
			ps.stack_a = NULL;
			return (0);
		}
		ps.size++;
		if (!(tmp = (int*)malloc(sizeof(int) * ps.size)))
			return (0);
		if (ps.stack_a)
			ft_memcpy(tmp, ps.stack_a, ps.size * sizeof(int));
		free(ps.stack_a);
		nb = ft_atoi(line);
		if ((line[0] == '-' && nb > 0) 
			|| ((line[0] == '+' || ft_isdigit(line[0])) && nb < 0))
			return (0);
		tmp[ps.size - 1] = nb;
		free(line);
		ps.stack_a = tmp;
	}
	print_stack_a(&ps);
	if (!(ps.stack_b = (int*)malloc(sizeof(int) * ps.size)))
			return (0);
	ft_bzero(ps.stack_b, ps.size * sizeof(int));
	free(ps.stack_a);
	ps.stack_a = NULL;
	free(ps.stack_b);
	ps.stack_b = NULL;
	// free(line);
	// line = NULL;
	return (0);
}

int				check_line(char *line)
{
	int i;

	i = 0;
	if (!line[0])
		return (0);
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
			i++;
		else
			return (0);
	}
	// if (9 <= i)
	// {
	// 	if (line[0] != '-' && )
	// }
	return (1);
}

void			print_stack_a(t_struct *ps)
{
	int i;

	i = 0;
	printf("size = %d\n", ps->size);
	while (i < ps->size)
	{
		printf("%d\n", ps->stack_a[i]);
		i++;
	}
}
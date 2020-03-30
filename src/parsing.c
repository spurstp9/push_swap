/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:05:07 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:05:16 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/prototypes.h"

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
			free(ps->stack_a.tab);
			ps->stack_a.tab = NULL;
			return (0);
		}
		if (!ft_realloc(&(ps->stack_a.tab), ++ps->stack_a.size, nb))
			return (0);
		i++;
	}
	return (1);
}

int				check_instr(t_struct *ps)
{
	int			i;
	char		*line;
	static char	*instr[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		i = 0;
		while (i < 11 && ft_strcmp(line, instr[i]))
			i++;
		free(line);
		line = NULL;
		if (i == 11)
			return (0);
		apply_instr(ps, i, 0);
	}
	return (1);
}

int				ft_realloc(int **tab, int size, int to_add)
{
	int			*tmp;

	tmp = NULL;
	if (!(tmp = (int*)malloc(sizeof(int) * size)))
		return (0);
	if (*tab)
		memcpy(tmp, *tab, size * sizeof(int));
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
	while (i < ps->stack_a.size)
	{
		if (*nb != (ps->stack_a.tab)[i])
			i++;
		else
			return (0);
	}
	return (1);
}

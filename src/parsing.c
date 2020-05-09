/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:05:07 by agardina          #+#    #+#             */
/*   Updated: 2020/05/09 22:28:23 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/prototypes.h"

int	check_args(int argc, char **argv, t_struct *ps)
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

int	check_instr(t_struct *ps)
{
	char	buf[5];
	int		ret;
	int		index;
	int		instr_nb;

	index = 0;
	while ((ret = read(0, buf + index, 1)) > 0)
	{
		if (buf[index] != '\n')
		{
			if (index < 3)
				index++;
			else
				return (0);
		}
		else
		{
			buf[index] = '\0';
			if ((instr_nb = ft_instr_cmp(buf)) == 11)
				return (0);
			apply_instr(ps, instr_nb, 0);
			index = 0;
		}
	}
	return (ret == -1 ? 0 : 1);
}

int	ft_instr_cmp(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (0);
	else if (!ft_strcmp(line, "sb"))
		return (1);
	else if (!ft_strcmp(line, "ss"))
		return (2);
	else if (!ft_strcmp(line, "pa"))
		return (3);
	else if (!ft_strcmp(line, "pb"))
		return (4);
	else if (!ft_strcmp(line, "ra"))
		return (5);
	else if (!ft_strcmp(line, "rb"))
		return (6);
	else if (!ft_strcmp(line, "rr"))
		return (7);
	else if (!ft_strcmp(line, "rra"))
		return (8);
	else if (!ft_strcmp(line, "rrb"))
		return (9);
	else if (!ft_strcmp(line, "rrr"))
		return (10);
	return (11);
}

int	ft_realloc(int **tab, int size, int to_add)
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

int	check_line(t_struct *ps, char *arg, int *nb)
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

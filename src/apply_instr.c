#include "../inc/push_swap.h"

int apply_instr(t_struct *ps)
{
	int i;
	static void (*f[4])(t_struct *ps, int instr_nb) = {&ft_s, &ft_p, &ft_r,
		&ft_rr};
	int instr;
	int res;

	i = 0;
	while (i < ps->instr_stock.size)
	{
		instr = ps->instr_stock.tab[i];
		res = get_ft_nb(instr);
		f[res](ps, instr);
		i++;
	}
	return (1);
}

int	get_ft_nb(int instr)
{
	if (instr <= 2)
		return (0);
	else if (instr <= 4)
		return (1);
	else if (instr <= 7)
		return (2);
	return (3);
}
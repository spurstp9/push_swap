#include "../inc/push_swap.h"

int apply_instr(t_struct *ps)
{
	int i;
	static void (*f)[4](t_struct *ps, int instr_nb) = {&ft_s, &ft_p, &ft_r,
		&ft_rr};
	int instr;

	i = 0;
	while (i < ps->instr_nb)
	{
		instr = instr_stock[i];
		f[get_ft_nb(instr)](ps, instr);
		i++;
	}
}

int	get_ft_nb(int instr)
{
	if (instr <= 3)
		return (0);
	else if (instr <= 5)
		return (1);
	else if (instr <= 8)
		return (2);
	return (3);
}
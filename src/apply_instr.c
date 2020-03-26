#include "../inc/push_swap.h"

int apply_instr(t_struct *ps, int instr, char write_it)
{
	static void (*f[4])(t_struct *ps, int instr_nb, char write_it) = {&ft_s, &ft_p, &ft_r,
		&ft_rr};

	f[get_ft_nb(instr)](ps, instr, write_it);
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
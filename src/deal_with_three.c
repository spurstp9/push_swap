#include "../inc/push_swap.h"

void	deal_with_three(t_struct *ps, void (*f[4])(t_struct *ps, int instr_nb, char write_it))
{
	int first;
	int second;
	int third;

	first = ps->stack_a.tab[ps->stack_a.begin];
	second = ps->stack_a.tab[ps->stack_a.begin + 1];
	third = ps->stack_a.tab[ps->stack_a.begin + 2];
	if (first > second && second < third && first < third)
		f[get_ft_nb(SA)](ps, SA, 1);
	else if (first > second && second > third && first > third)
	{
		f[get_ft_nb(SA)](ps, SA, 1);
		f[get_ft_nb(RRA)](ps, RRA, 1);
	}
	else if (first > second && second < third && first > third)
		f[get_ft_nb(RA)](ps, RA, 1);
	else if (first < second && second > third && first < third)
	{
		f[get_ft_nb(SA)](ps, SA, 1);
		f[get_ft_nb(RA)](ps, RA, 1);
	}
	else if (first < second && second > third && first > third)
		f[get_ft_nb(RRA)](ps, RRA, 1);
}
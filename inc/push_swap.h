#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# include <stdio.h>

typedef struct	s_stack
{
	int			*tab;
	int			begin;
	int			size;
}				t_stack;

typedef struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_stack		instr_stock;
}				t_struct;

void			print_stack_a(t_struct *ps);
void			print_stack_b(t_struct *ps);

int				apply_instr(t_struct *ps);
void			apply_p(t_stack *dest, t_stack *source);
void			apply_r(t_stack *stack);
void			apply_rr(t_stack *stack);
void			apply_s(t_stack *stack);
int				check_args(int argc, char **argv, t_struct *ps);
int				check_instr(t_struct *ps);
int				check_order(t_stack stack_a);
int				check_line(t_struct *ps, char *arg, int *nb);
void			ft_init(t_struct *ps);
int				ft_realloc(int **tab, int size, int to_add);
void			ft_p(t_struct *ps, int instr_nb);
void			ft_r(t_struct *ps, int instr_nb);
void			ft_rr(t_struct *ps, int instr_nb);
void			ft_s(t_struct *ps, int instr_nb);
int				get_ft_nb(int instr);

#endif
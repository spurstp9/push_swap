#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct	s_stack
{
	int			*tab;
	int			begin;
	int			size;
};

typedef struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_stack		instr_stock;
}				t_struct;

void			print_stack_a(t_struct *ps);

int				apply_instr(t_struct *ps);
void			apply_p(t_stack dest, t_stack source);
void			apply_r(t_stack stack);
void			apply_rr(t_stack stack);
void			apply_s(t_stack stack);
int				check_args(int argc, char **argv, t_struct *ps);
int				check_instr(t_struct *ps);
int				check_line(t_struct *ps, char *arg, int *nb);
void			ft_init(t_struct *ps);
int				ft_realloc(int **tab, int size, int to_add);
void			ft_p(t_struct *ps, int instr_nb);
void			ft_r(t_struct *ps, int instr_nb);
void			ft_rr(t_struct *ps, int instr_nb);
void			ft_s(t_struct *ps, int instr_nb);
int				get_ft_nb(int instr);

#endif
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

typedef struct	s_struct
{
	int*		stack_a;
	int*		stack_b;
	int			size;
}				t_struct;

void			print_stack_a(t_struct *ps);

int				check_args(int argc, char **argv, t_struct *ps);
int				check_instr(int *instr_stock);
int				check_line(t_struct *ps, char *arg, int *nb);
int				ft_realloc(int **tab, int size, int to_add);

#endif
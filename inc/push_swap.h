#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_struct
{
	int*		stack_a;
	int*		stack_b;
	int			size;
}				t_struct;

void			print_stack_a(t_struct *ps);

int				check_line(char *line);

#endif
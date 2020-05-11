/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:23:49 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:06:38 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H

# define PROTOTYPES_H
# include "../libft/includes/libft.h"
# include "structs.h"
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

int				apply_instr(t_struct *ps, int instr, char write_it);
void			apply_p(t_stack *dest, t_stack *source);
void			apply_r(t_stack *stack);
void			apply_rr(t_stack *stack);
void			apply_s(t_stack *stack);
int				check_args(int argc, char **argv, t_struct *ps);
int				check_instr(t_struct *ps);
int				check_line(t_struct *ps, char *arg, int *nb);
int				check_order(t_stack stack_a);
int				chunk_sort(t_struct *ps, t_chunk *ch, int nb);
void			chunk_sort_loop(t_struct *ps, int nb);
void			find_instr(t_struct *ps);
int				ft_free_and_return(t_struct *ps);
void			ft_init(t_struct *ps);
int				ft_instr_cmp(char *line);
void			ft_move_back_to_a(t_struct *ps);
void			ft_move_to_b(t_struct *ps, int rank, int instr);
void			ft_p(t_struct *ps, int instr_nb, char write_it);
void			ft_r(t_struct *ps, int instr_nb, char write_it);
int				ft_realloc(t_stack *stack, int to_add);
void			ft_rr(t_struct *ps, int instr_nb, char write_it);
void			ft_s(t_struct *ps, int instr_nb, char write_it);
void			ft_swap(int *a, int *b);
int				get_ft_nb(int instr);
int				get_max(t_stack stack);
int				get_max_index(t_stack stack);
int				get_min(t_stack stack);
int				get_min_index(t_stack stack);
int				get_rank(t_stack stack, t_chunk ch, char up_or_down);
void			init_chunk(t_struct *ps, t_chunk *ch, int nb);
int				is_stack_empty(t_stack *stack);
int				replace_values_by_rank(t_stack *stack);
void			selection_sort(t_struct *ps);
void			selection_sort_loop(t_struct *ps);
int				sort_last_three(t_struct *ps);
int				sort_last_two(t_struct *ps);
int				stack_size(t_stack *stack);

#endif

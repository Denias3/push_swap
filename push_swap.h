/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:21:33 by emeha             #+#    #+#             */
/*   Updated: 2019/04/08 09:51:22 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef	struct		s_stack
{
	int *num;
	int size;
	int max;
}					t_stack;

typedef	struct		s_swap
{
	t_stack *a;
	t_stack *b;
}					t_swap;

typedef	struct		s_best
{
	int a;
	int b;
	int wh_a;
	int wh_b;
}					t_best;

int					*check_arg(int arc, char **arg, int *size, int start);
int					diff_num(int *num, int len);
t_stack				*create_t_stack(int *num, int max);
t_swap				*create_t_swap(int ac, char **av, int start);
void				print_swap(t_swap *w);
int					check_number_space(char *str);
void				operations_swap(t_stack *st);
void				operations_push(t_stack *st1, t_stack *st2);
void				operations_rotate(t_stack *st);
void				operations_reverse_rotate(t_stack *st);
void				com_sa(t_swap *w, int pr);
void				com_sb(t_swap *w, int pr);
void				com_ss(t_swap *w, int pr);
void				com_pa(t_swap *w, int pr);
void				com_pb(t_swap *w, int pr);
void				com_ra(t_swap *w, int pr);
void				com_rb(t_swap *w, int pr);
void				com_rr(t_swap *w, int pr);
void				com_rra(t_swap *w, int pr);
void				com_rrb(t_swap *w, int pr);
void				com_rrr(t_swap *w, int pr);
int					validation_check(t_swap *w);
void				solve(t_swap *w);
int					*position(t_stack *st);
int					serc_num(t_swap *w, int sr);
int					serc_num_more(t_swap *w, int *num, int sr, int *res);
int					serc_num_more_2(t_swap *w, int *num, int sr);
int					validation_stack(t_swap *w);
void				push_b(t_swap *w);
void				check_three(t_swap *w);
int					comparison(t_best *best, t_best *tmp);
void				free_t_swap(t_swap *w);

#endif

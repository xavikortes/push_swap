/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:02:28 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/16 14:11:21 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKER_H
# define STACKER_H

# include <stdlib.h>
# include "../bench/bench.h"
# include "../../libft/libft.h"

typedef struct s_state
{
	t_list	*a;
	t_list	*b;
	t_bench	*bench;
}	t_state;

/* stacker */
void		fill_state(int *nums, int len, t_state *state);
void		free_state(t_state *state, void (*del)(void *));
void		stack_operate(t_operation op, t_state *state);
t_operation	get_operation(char *op);
int			*export_state(t_state *state);

/* stack operations */
void		swap(t_list **lst);
void		push(t_list **lst, int *n);
void		rotate(t_list **lst);
void		reverse_rotate(t_list **lst);

/* stacker utils */
t_list		*stack_create(int *nums, int len);
t_list		*stack_pop(t_list **lst);
t_list		*stack_shift(t_list **lst);
void		stack_push(t_list **lst, t_list *new);

#endif

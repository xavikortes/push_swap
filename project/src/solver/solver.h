/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:56:59 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/17 20:37:47 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "../parser/parser.h"
# include "../stacker/stacker.h"
# include "../analyzer/analyzer.h"
# include "../bench/bench.h"
# include "../../libft/libft.h"

void	do_operation(char *op, t_state *state);
void	solve_sorting(t_state *state, t_config *config);
void	solve_two(t_state *state);
void	solve_three(t_state *state);

void	bubble_sort(t_state *state, int size, int in_stack_a);
void	chunk_sort(t_state *state, t_config *config);
void	merge_sort(t_state *state, int size, int in_stack_a);

/* chunk_utils.c */
int		get_max_pos(t_list *stack);
int		*get_sorted_copy(const int *numbers, int size);

#endif

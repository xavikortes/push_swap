/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:03:06 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/20 20:19:47 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

/* 1. Calculates total cost (distance in B + distance en A) */
static int	get_cost(t_state *state, int pos_b, int val)
{
	int	cost_b;
	int	cost_a;
	int	target;
	int	size_b;
	int	size_a;

	size_b = ft_lstsize(state->b);
	size_a = ft_lstsize(state->a);
	target = get_target(state->a, val);
	cost_b = calc_dist(pos_b, size_b);
	cost_a = calc_dist(target, size_a);
	if ((pos_b <= size_b / 2 && target <= size_a / 2)
		|| (pos_b > size_b / 2 && target > size_a / 2))
	{
		if (cost_b > cost_a)
			return (cost_b);
		return (cost_a);
	}
	return (cost_b + cost_a);
}

/* 2. Iterates B and return the cheapest index */
static int	find_cheapest(t_state *state, int *val_out)
{
	t_list	*cur;
	int		idx;
	int		best_idx;
	int		min_cost;
	int		cost;

	min_cost = 2147483647;
	best_idx = 0;
	idx = 0;
	cur = state->b;
	while (cur)
	{
		cost = get_cost(state, idx, *(int *)cur->content);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_idx = idx;
			*val_out = *(int *)cur->content;
			if (min_cost <= 1)
				break ;
		}
		cur = cur->next;
		idx++;
	}
	return (best_idx);
}

/* 3. Entrypoint: Push A to B, reinsert by lowest cost, and align to minimum */
void	turk_sort(t_state *state, int size)
{
	int		best_b;
	int		val;
	int		target;
	long	avg;

	if (size <= 3)
		return (solve_three(state));
	avg = get_stack_average(state->a);
	while ((int)ft_lstsize(state->a) > 3)
	{
		do_operation("pb\n", state);
		if (*(int *)state->b->content < avg)
			do_operation("rb\n", state);
	}
	solve_three(state);
	while (state->b)
	{
		best_b = find_cheapest(state, &val);
		target = get_target(state->a, val);
		sync_rotations(state, &best_b, &target);
		rotate_to_top(state, best_b, ft_lstsize(state->b), 0);
		rotate_to_top(state, target, ft_lstsize(state->a), 1);
		do_operation("pa\n", state);
	}
	rotate_to_top(state, get_min_pos(state->a), ft_lstsize(state->a), 1);
}

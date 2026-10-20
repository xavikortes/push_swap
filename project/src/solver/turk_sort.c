/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:03:06 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/20 18:51:53 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void	rotate_to_top(t_state *state, int pos, int size, int in_stack_a)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (in_stack_a)
				do_operation("ra\n", state);
			else
				do_operation("rb\n", state);
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			if (in_stack_a)
				do_operation("rra\n", state);
			else
				do_operation("rrb\n", state);
		}
	}
}

/* Fase 2: Localizar el destino en A (get_target)
Para un valor val de B, determinar en qué posición de A debe insertarse */
static int	get_target(t_list *a, int val)
{
	t_list	*cur;
	long	best_val;
	int		target_pos;
	int		idx;

	best_val = 21474836480L;
	target_pos = 0;
	idx = 0;
	cur = a;
	while (cur)
	{
		if (*(int *)cur->content > val && *(int *)cur->content < best_val)
		{
			best_val = *(int *)cur->content;
			target_pos = idx;
		}
		cur = cur->next;
		idx++;
	}
	if (best_val != 21474836480L)
		return (target_pos);
	return (get_min_pos(a));
}

/* 1. Calcula el coste TOTAL (distancia en B + distancia en A) */
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
	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	if (target <= size_a / 2)
		cost_a = target;
	else
		cost_a = size_a - target;
	return (cost_b + cost_a);
}

/* 2. Recorre B y devuelve el índice del más barato */
static int	find_cheapest(t_state *state, int *val_out)
{
	t_list	*cur;
	int		idx;
	int		best_idx;
	int		min_cost;

	min_cost = 2147483647;
	best_idx = 0;
	idx = 0;
	cur = state->b;
	while (cur && idx < min_cost)
	{
		if (get_cost(state, idx, *(int *)cur->content) < min_cost)
		{
			min_cost = get_cost(state, idx, *(int *)cur->content);
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

/* 3. Entrypoint: Vacía A, reinserta por coste mínimo y alinea el menor */
void	turk_sort(t_state *state, int size)
{
	int	best_b;
	int	val;
	int	target;

	if (size <= 3)
		return (solve_three(state));
	while ((int)ft_lstsize(state->a) > 3)
		do_operation("pb\n", state);
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

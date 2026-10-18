/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:27:47 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/17 20:52:37 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

/* Calculates chunk aprox size */
static int	calculate_size_chunk(int size)
{
	int	chunk;

	chunk = (size * 5) / 100 + 10;
	if (chunk > 35)
		chunk = 35;
	if (chunk < 5)
		chunk = 5;
	return (chunk);
}

/* 1. BLOCK DEFINITION: Filtering from A to B */
static void	push_chunks_to_b(t_state *state, int *sorted, int size)
{
	int	size_chunk;
	int	limit_sup;
	int	num_top;
	int	idx;

	size_chunk = calculate_size_chunk(size);
	limit_sup = size_chunk;
	while (state->a)
	{
		num_top = *(int *)state->a->content;
		idx = limit_sup - 1;
		if (idx >= size)
			idx = size - 1;
		if (num_top <= sorted[idx])
		{
			do_operation("pb\n", state);
			if (num_top <= sorted[limit_sup - (size_chunk / 2)])
				do_operation("rb\n", state);
			if ((int)ft_lstsize(state->b) >= limit_sup)
			{
				limit_sup += size_chunk;
				if (limit_sup > size)
					limit_sup = size;
			}
		}
		else
			do_operation("ra\n", state);
	}
}

/* 2. GREEDY EXTRACTION: Push back sorted from B to A */
static void	sorted_chunks_to_a(t_state *state)
{
	int	max_pos;
	int	updated_b_size;
	int	steps;

	while (state->b)
	{
		max_pos = get_max_pos(state->b);
		updated_b_size = ft_lstsize(state->b);
		if (max_pos <= updated_b_size / 2)
		{
			while (max_pos-- > 0)
				do_operation("rb\n", state);
		}
		else
		{
			steps = updated_b_size - max_pos;
			while (steps-- > 0)
				do_operation("rrb\n", state);
		}
		do_operation("pa\n", state);
	}
}

/* Medium algorithm sorting CHUNK_SORT */
void	chunk_sort(t_state *state, t_config *config)
{
	int	*sorted;

	sorted = get_sorted_copy(config->numbers, config->size);
	if (!sorted)
		return ;
	push_chunks_to_b(state, sorted, config->size);
	sorted_chunks_to_a(state);
	free(sorted);
}

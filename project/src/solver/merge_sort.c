/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 10:04:59 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/19 12:50:28 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void	swaps(t_state *state)
{
	int	sa;
	int	sb;

	sa = *((int *) state->a->content) > *((int *) state->a->next->content);
	sb = *((int *) state->b->content) < *((int *) state->b->next->content);
	if (sa && sb)
		do_operation("ss\n", state);
	else if (sa)
		do_operation("sa\n", state);
	else if (sb)
		do_operation("sb\n", state);
}

static void	split_in_half(t_state *state, int size, int in_stack_a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (in_stack_a)
			do_operation("pb\n", state);
		else
			do_operation("pa\n", state);
		i++;
	}
}

static void	merge(t_state *state, int this_size, int other_size, int in_stack_a)
{
	int	reverse_count;

	reverse_count = 0;
	while (other_size > 0)
	{
		while (*((int *) state->a->content) < *((int *) state->b->content) && reverse_count < this_size)
		{
			if (in_stack_a)
				do_operation("ra\n", state);
			else
				do_operation("rb\n", state);
			reverse_count++;
		}
		if (in_stack_a)
			do_operation("pa\n", state);
		else
			do_operation("pb\n", state);
		other_size--;
		while (reverse_count > 0)
		{
			if (in_stack_a)
				do_operation("rra\n", state);
			else
				do_operation("rrb\n", state);
			reverse_count--;
		}
	}
}

void	merge_sort(t_state *state, int size, int in_stack_a)
{
	int	other_size;

	if (size == 1)
		return ;
	if (size == 2)
		return (swaps(state));
	other_size = size / 2;
	split_in_half(state, other_size, in_stack_a);
	merge_sort(state, other_size, (in_stack_a + 1) % 2);
	merge_sort(state, size - other_size, in_stack_a);
	merge(state, size - other_size, other_size, in_stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:02:28 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/20 20:16:07 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

/* Rotates stack A or B until the given position reaches the top */
void	rotate_to_top(t_state *state, int pos, int size, int in_stack_a)
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

/* Computes arithmetic mean of stack values to split B on push */
long	get_stack_average(t_list *state)
{
	long	sum;
	int		count;

	sum = 0;
	count = 0;
	while (state)
	{
		sum += *(int *)state->content;
		count++;
		state = state->next;
	}
	if (!count)
		return (0);
	return (sum / count);
}

/* Finds smallest value greater than val in A, or returns min value index */
int	get_target(t_list *a, int val)
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

/* Calculates shortest rotation distance to the top (forward or reverse) */
int	calc_dist(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

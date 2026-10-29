/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:36:59 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/19 13:11:33 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	swap_values(t_state *state)
{
	do_operation("pa\n", state);
	do_operation("ra\n", state);
	do_operation("pb\n", state);
}

void	bubble_sort(t_state *state, int size)
{
	int	n;
	int	i;

	n = size;
	while (n > 1)
	{
		i = 0;
		do_operation("pb\n", state);
		while (i < n)
		{
			if (*((int *) state->a->content) < *((int *) state->b->content))
				swap_values(state);
			else
				do_operation("ra\n", state);
			i++;
		}
		n--;
	}
	while (n < size)
	{
		do_operation("pa\n", state);
		n++;
	}
}

void	solve_two(t_state *state)
{
	int	first;
	int	second;

	first = *((int *)state->a->content);
	second = *((int *)state->a->next->content);
	if (first > second)
		do_operation("sa\n", state);
}

void	solve_three(t_state *state)
{
	int	first;
	int	second;
	int	third;

	first = *((int *)state->a->content);
	second = *((int *)state->a->next->content);
	third = *((int *)state->a->next->next->content);
	if (first > second && second < third && first < third)
		do_operation("sa\n", state);
	else if (first > second && second > third)
	{
		do_operation("sa\n", state);
		do_operation("rra\n", state);
	}
	else if (first > second && second < third && first > third)
		do_operation("ra\n", state);
	else if (first < second && second > third && first < third)
	{
		do_operation("sa\n", state);
		do_operation("ra\n", state);
	}
	else if (first < second && second > third && first > third)
		do_operation("rra\n", state);
}

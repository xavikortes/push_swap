/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 20:16:34 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/20 18:42:11 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

/* Get maximum number position*/
int	get_max_pos(t_list *stack)
{
	int	max_val;
	int	max_pos;
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	max_pos = 0;
	max_val = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > max_val)
		{
			max_val = *(int *)stack->content;
			max_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_pos);
}

int	get_min_pos(t_list *stack)
{
	int	min_val;
	int	min_pos;
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	min_pos = 0;
	min_val = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < min_val)
		{
			min_val = *(int *)stack->content;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

/* Gets copy from config->numbers and return sorted array */
int	*get_sorted_copy(const int *numbers, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	ft_memcpy(sorted, numbers, sizeof(int) * size);
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
		}
	}
	return (sorted);
}

/* Aux function to sync rotations rr && rrr */
void	sync_rotations(t_state *state, int *best_b, int *target)
{
	int	size_b;
	int	size_a;

	size_b = (int)ft_lstsize(state->b);
	size_a = (int)ft_lstsize(state->a);
	if (*best_b <= size_b / 2 && *target <= size_a / 2)
	{
		while (*best_b > 0 && *target > 0 && (*best_b)-- && (*target)--)
			do_operation("rr\n", state);
	}
	else if (*best_b > size_b / 2 && *target > size_a / 2)
	{
		while (*best_b < size_b && *target < size_a
			&& (*best_b)++ && (*target)++)
			do_operation("rrr\n", state);
	}
}

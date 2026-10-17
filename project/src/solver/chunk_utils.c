/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 20:16:34 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/17 20:17:40 by fernfern         ###   ########.fr       */
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

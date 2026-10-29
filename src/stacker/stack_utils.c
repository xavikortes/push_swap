/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:33:39 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/15 15:48:39 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacker.h"

t_list	*stack_create(int *nums, int len)
{
	int		i;
	t_list	*stack;

	if (len == 0)
		return (NULL);
	i = len - 1;
	stack = NULL;
	while (i >= 0)
		push(&stack, &nums[i--]);
	return (stack);
}

t_list	*stack_pop(t_list **lst)
{
	t_list	*node;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	node = *lst;
	*lst = node->next;
	node->next = NULL;
	return (node);
}

t_list	*stack_shift(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	node = *lst;
	if (node->next == NULL)
		return (NULL);
	while (node->next->next != NULL)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	return (tmp);
}

void	stack_push(t_list **lst, t_list *new)
{
	ft_lstadd_front(lst, new);
}

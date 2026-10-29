/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:14:03 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/15 15:51:14 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacker.h"

void	swap(t_list **lst)
{
	t_list	*n1;
	t_list	*n2;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	n1 = stack_pop(lst);
	n2 = stack_pop(lst);
	stack_push(lst, n1);
	stack_push(lst, n2);
}

void	push(t_list **lst, int *n)
{
	t_list	*new;

	if (lst == NULL)
		return ;
	new = ft_lstnew(n);
	if (new == NULL)
		return ;
	stack_push(lst, new);
}

void	rotate(t_list **lst)
{
	t_list	*head;

	if (lst == NULL || *lst == NULL)
		return ;
	head = stack_pop(lst);
	head->next = NULL;
	ft_lstadd_back(lst, head);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*tail;

	if (lst == NULL || *lst == NULL)
		return ;
	tail = stack_shift(lst);
	if (tail)
		stack_push(lst, tail);
}

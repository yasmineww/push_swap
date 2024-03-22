/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:17:26 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/22 18:14:38 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **stack)
{
	t_list	*node1;
	t_list	*node2;

	if (*stack == NULL)
		return ;
	node1 = *stack;
	node2 = node1->next;
	if (node1 != NULL && node2 != NULL)
	{
		node1->next = node2->next;
		node2->next = node1;
	}
	*stack = node2;
}

void	rotate(t_list **stack)
{
	t_list	*old_head;
	t_list	*new_head;

	if (*stack == NULL)
		return ;
	old_head = *stack;
	new_head = (*stack)->next;
	old_head->next = NULL;
	*stack = new_head;
	while (new_head->next != NULL)
		new_head = new_head->next;
	new_head->next = old_head;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*new_head;
	t_list	*last_node;

	if (*stack == NULL)
		return ;
	new_head = *stack;
	while (new_head->next != NULL)
	{
		last_node = new_head;
		new_head = new_head->next;
	}
	last_node->next = NULL;
	new_head->next = *stack;
	*stack = new_head;
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_stack;

	if (*stack_b == NULL || *stack_a == NULL)
		return ;
	top_stack = *stack_b;
	*stack_b = (*stack_b)->next;
	top_stack->next = *stack_a;
	*stack_a = top_stack;
}

int	check_sort(t_list **stack_a)
{
	t_list	*node1;
	t_list	*node2;

	node1 = *stack_a;
	while (node1->next != NULL)
	{
		node2 = node1->next;
		while (node2 != NULL)
		{
			if (node1->content > node2->content)
				return (1);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (0);
}

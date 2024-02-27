/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:17:26 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/27 13:24:41 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*node1;
	t_list	*node2;
	int		temp;

	node1 = *stack;
	node2 = node1->next;
	if (node1 != NULL && node2 != NULL)
	{
		temp = node1->content;
		node1->content = node2->content;
		node2->content = temp;
	}
}

void	rotate(t_list **stack)
{
	t_list	*old_head;
	t_list	*new_head;

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

	top_stack = *stack_b;
	*stack_b = (*stack_b)->next;
	top_stack->next = *stack_a;
	*stack_a = top_stack;
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		size;

	size = 0;
	ptr = *stack_a;
	*stack_b = NULL;
	while (ptr->next != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	if ((size = 2) && check_sort(stack_a))
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	// else if ((size = 3) && check_sort(stack_a))
	// 	sort_3(stack_a);
	// else if ((size == 5 || size == 4) && check_sort(stack_a))
	// 	sort_5(stack_a, stack_b);
	// else
	// 	sort_algo(&stack_a, stack_b);
}

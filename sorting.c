/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:04:38 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/14 22:32:44 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	index_stack(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1 != NULL)
	{
		temp2 = *stack;
		temp1->index = 1;
		while (temp2 != NULL)
		{
			if (temp1->content > temp2->content)
				temp1->index += 1;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	index_3(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1 != NULL)
	{
		temp2 = *stack;
		temp1->index_3 = 1;
		while (temp2 != NULL)
		{
			if (temp1->content > temp2->content)
				temp1->index_3 += 1;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	sort_3(t_list **stack_a)
{
	index_3(stack_a);
	if ((*stack_a)->index_3 == 3)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if ((*stack_a)->next->index_3 == 3)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	if ((*stack_a)->index_3 > (*stack_a)->next->index_3)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	// int	size;

	// size = stack_size(stack_a);
	// if (size == 2 && check_sort(stack_a))
	// {
	// 	swap(stack_a);
	// 	write(1, "sa\n", 3);
	// }
	// else if ((size == 3) && check_sort(stack_a))
	// 	sort_3(stack_a);
	// else if ((size > 3) && check_sort(stack_a))
		algo(stack_a, stack_b);
}

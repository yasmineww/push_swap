/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:04:38 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/18 02:54:12 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = stack_size(stack_a);
	index_4(stack_a);
	while (stack_size(stack_a) != 3)
	{
		if ((*stack_a)->index_4 == 1)
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
	if (check_sort(stack_a))
		sort_3(stack_a);
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	index_5(stack_a);
	while (stack_size(stack_a) != 4)
	{
		if ((*stack_a)->index_5 == 1)
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
	if (check_sort(stack_a))
		sort_4(stack_a, stack_b);
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

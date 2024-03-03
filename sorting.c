/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:04:38 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/03 01:14:11 by ymakhlou         ###   ########.fr       */
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

void	sort_3(t_list **stack_a)
{
	int size;

	index_stack(stack_a);
	size = stack_size(stack_a);
	if ((*stack_a)->index == 3)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if ((*stack_a)->next->index == 3)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	algo(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = stack_size(stack_a);
	while (stack_size(stack_a) > 3)
	{
		if ((*stack_a)->index <= (size / 2))
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
		if ((*stack_a)->index < size - 2)
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
		}
	}
	if ((stack_size(stack_a) == 3) && check_sort(stack_a))
		sort_3(stack_a);
	calc_position(stack_b);
	calc_cost(stack_b);
	calc_target(stack_a, stack_b);
	// while(*stack_b)
	// {
	// 	printf("content ---> %d //// target ---> %d /// index ---> %d\n", (*stack_b)->content, (*stack_b)->target, (*stack_b)->index);
	// 	(*stack_b) = (*stack_b)->next;
	// }
}

void	calc_position(t_list **stack)
{
	t_list	*temp;
	int i;

	i = 0;
	temp = *stack;
	while(temp)
	{
		temp->position = i;
		i++;
		temp = temp->next;
	}
}

void	calc_cost(t_list **stack)
{
	t_list	*temp;
	int		size;
	int		i;

	calc_position(stack);
	size = stack_size(stack);
	temp = *stack;
	i = (size / 2);
	if (size % 2 == 1)
		size = size + 1;
	while (temp)
	{
		if (temp->position < (size / 2))
			temp->cost_b = temp->position;
		else
		{
			temp->cost_b = i;
			temp->cost_b *= -1; 
			i--;
		}
		temp = temp->next;
	}
}

void	calc_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp2 = *stack_b;
	while (temp2)
	{
		temp1 = *stack_a;
		while (temp1)
		{
			temp2->target = temp1->index;
			if (temp1->index > temp2->index)
			{
				temp2->target = temp1->index;
				break ;
			}
			else
				temp1 = temp1->next;	
		}
		temp2 = temp2->next;
	}
}

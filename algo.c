/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:58:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/22 21:11:59 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_position(t_list **stack)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
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
			temp->cost = temp->position;
		else
		{
			temp->cost = i;
			temp->cost *= -1;
			i--;
		}
		temp = temp->next;
	}
}

void	calc_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp1;
	t_list	*temp2;
	int		max;

	temp2 = *stack_b;
	while (temp2)
	{
		max = 2147483647;
		temp1 = *stack_a;
		while (temp1)
		{
			if ((temp1->index > temp2->index) && temp1->index < max)
			{
				max = temp1->index;
				temp2->target_cost = temp1->cost;
			}
			temp1 = temp1->next;
		}
		temp2 = temp2->next;
	}
}

void	push_rest(t_list **stack_a, t_list **stack_b, int size)
{
	while (stack_size(stack_a) > 3)
	{
		if ((*stack_a)->index < size)
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
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;

	size = stack_size(stack_a);
	i = 0;
	while ((stack_size(stack_a) > size / 2) && (i < size) && (size > 6))
	{
		if ((*stack_a)->index <= size / 2)
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
		i++;
	}
	push_rest(stack_a, stack_b, size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:56 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/21 23:33:04 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute(int cost)
{
	if (cost < 0)
		cost *= -1;
	return (cost);
}

void	apply_actions(int cost_a, int cost_b, t_list **stack_a,
			t_list **stack_b)
{
	if (cost_a < 0 && cost_b < 0)
		rrr(&cost_a, &cost_b, stack_a, stack_b);
	else if (cost_a > 0 && cost_b > 0)
		rr(&cost_a, &cost_b, stack_a, stack_b);
	rotate_a(&cost_a, stack_a);
	rotate_b(&cost_b, stack_b);
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	best_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp1;
	int		cost_a;
	int		cost_b;
	int		max;

	temp1 = *stack_b;
	max = 2146473647;
	while (temp1)
	{
		if (absolute(temp1->cost) + absolute(temp1->target_cost) < max)
		{
			max = absolute(temp1->cost) + absolute(temp1->target_cost);
			cost_a = temp1->target_cost;
			cost_b = temp1->cost;
		}
		temp1 = temp1->next;
	}
	apply_actions(cost_a, cost_b, stack_a, stack_b);
}

void	last_sort(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	calc_position(stack_a);
	while (temp->next && temp->index != 1)
		temp = temp->next;
	if (temp->position < (stack_size(stack_a) / 2))
	{
		while (temp->position > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			temp->position--;
		}
	}
	else
	{
		while (temp->position < stack_size(stack_a))
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			temp->position++;
		}
	}
}

void	free_leaks(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

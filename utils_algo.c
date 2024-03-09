/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:56 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/09 20:50:01 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute(int cost)
{
	if (cost < 0)
		cost *= -1;
	return (cost);
}

void	compare_elements(t_list *temp1)
{
	t_list	*temp2;
	int		tr;

	while (temp1->next)
	{
		temp2 = temp1->next;
		tr = 1;
		while (temp2)
		{
			if (temp1->sum < temp2->sum)
				temp2 = temp2->next;
			else
				break ;
			tr = 0;
		}
		if (tr == 0)
			break;
		temp1 = temp1->next;
	}
}

void	apply_actions(t_list *temp_b, t_list **stack_a, t_list **stack_b)
{
	if (temp_b->cost < 0 && temp_b->target_cost < 0)
		rrr(temp_b, stack_a, stack_b);
	else if (temp_b->cost > 0 && temp_b->target_cost > 0)
		rr(temp_b, stack_a, stack_b);		
	rotate_a(temp_b, stack_a);
	rotate_b(temp_b, stack_b);
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	best_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp1;

	temp1 = *stack_b;
	while (temp1)
	{
		temp1->sum = absolute(temp1->cost) + absolute(temp1->target_cost);
		temp1 = temp1->next;
	}
	temp1 = *stack_b;
	compare_elements(temp1);
	apply_actions(temp1, stack_a, stack_b);
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
		while (temp->position < stack_size(stack_a))
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			temp->position++;
		}
	}
	else
	{
		while (temp->position > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			temp->position--;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:52:37 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/06 20:24:58 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list *temp_b, t_list **stack_a, t_list **stack_b)
{
	while (temp_b->cost != 0 && temp_b->target_cost != 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
		temp_b->cost++;
		temp_b->target_cost++;
	}
}

void	rr(t_list *temp_b, t_list **stack_a, t_list **stack_b)
{
	while (temp_b->cost != 0 && temp_b->target_cost != 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
		temp_b->target_cost--;
		temp_b->cost--;
	}
}

void	rotate_a(t_list *temp_b, t_list **stack_a)
{
	while (temp_b->target_cost != 0)
	{
		if(temp_b->target_cost > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			temp_b->target_cost--;
		}
		else if (temp_b->target_cost < 0)
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			temp_b->target_cost++;
		}
	}
}

void	rotate_b(t_list *temp_b, t_list **stack_b)
{
	while (temp_b->cost != 0)
	{
		if(temp_b->cost > 0)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
			temp_b->cost--;
		}
		else if (temp_b->cost < 0)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
			temp_b->cost++;
		}
	}
}

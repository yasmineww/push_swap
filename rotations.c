/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:52:37 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/15 23:19:54 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *cost_a, int *cost_b, t_list **stack_a, t_list **stack_b)
{
	while (*cost_a != 0 && *cost_b != 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rr(int *cost_a, int *cost_b, t_list **stack_a, t_list **stack_b)
{
	while (*cost_a != 0 && *cost_b != 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rotate_a(int *cost_a, t_list **stack_a)
{
	while (*cost_a != 0)
	{
		if(*cost_a > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			(*cost_a)++;
		}
	}
}

void	rotate_b(int *cost_b, t_list **stack_b)
{
	while (*cost_b != 0)
	{
		if(*cost_b > 0)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
			(*cost_b)++;
		}
	}
}

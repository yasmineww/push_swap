/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:58:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/03 21:59:25 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

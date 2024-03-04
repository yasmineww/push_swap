/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:43:56 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/04 19:06:50 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute(int cost)
{
	if (cost < 0)
		cost *= -1;
	return (cost);
}

void	best_move(t_list **stack_b)
{
	t_list	*temp1;
	t_list	*temp2;
	int		tr;

	temp1 = *stack_b;
	while (temp1)
	{
		temp1->sum = absolute(temp1->cost) + absolute(temp1->target_cost);
		printf(" cost is %d\n", temp1->sum);
		temp1 = temp1->next;
	}
	temp1 = *stack_b;
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
	//if (temp1->cost > 0 && temp1->target_cost > 0)
	printf("node to push is --> {%d} \n", temp1->content);
}

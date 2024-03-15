/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:58:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/15 23:21:58 by ymakhlou         ###   ########.fr       */
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
int	biggest(t_list **stack_a)
{
	t_list	*temp_a;
	int		big;

	temp_a = *stack_a;
	big = temp_a->index;
	while (temp_a)
	{
		if (temp_a->next && temp_a->next->index > temp_a->index)
			big = temp_a->next->index;
		temp_a = temp_a->next;
	}
	printf("big is %d\n", big);
	return (big);
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
				// printf("temp1.index |%d|\t temp2.index |%d|\t\n", temp1->index, temp2->index);
				max = temp1->index;
				temp2->target_cost = temp1->cost;
			}
			// else if (temp2->index > biggest(stack_a))
			// {
			// 	temp2->target_cost = -1;
			// }
			temp1 = temp1->next;
		}
		temp2 = temp2->next;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = stack_size(stack_a);
	while (stack_size(stack_a) > 3)
	{
		if ((*stack_a)->index < size - 2)
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

int	my_stack_size(t_list **stack_a)
{
	t_list	*ptr;
	int		size;

	size = 0;
	ptr = *stack_a;
	while (ptr)
	{
		size++;
		// printf("num=%d\n", ptr->content);
		ptr = ptr->next;
	}
	return (size);
}


void	printerB(t_list **stack)
{
	puts("-------STACKB--------------");
	t_list *temp2 = *stack;
	while (temp2)
	{
		printf("content B [%d]\t index == %d\tcostB-->%d  targetCost-->%d\n", temp2->content ,temp2->index ,temp2->cost,temp2->target_cost);
		temp2 = temp2->next;
	}
}

void	printerA(t_list **stack)
{
	puts("----------STACKA-----------");
	t_list *temp1 = *stack;
	while (temp1)
	{
		printf("content A [%d]\t index == %d\tcostA-->%d\n", temp1->content, temp1->index ,temp1->cost);
		temp1 = temp1->next;
	}
}

void	algo(t_list **stack_a, t_list **stack_b)
{
	index_stack(stack_a);
	push_to_b(stack_a, stack_b);
	if (check_sort(stack_a))
		sort_3(stack_a);
	while (*stack_b)
	{
		calc_cost(stack_a);
		calc_cost(stack_b);
		calc_target(stack_a, stack_b);
		// printerB(stack_b);
		// printerA(stack_a);
		best_move(stack_a, stack_b);
	}
	if (check_sort(stack_a) == 0)
		return ;
	last_sort(stack_a);
}

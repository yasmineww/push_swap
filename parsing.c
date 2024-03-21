/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:10:01 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/19 02:25:21 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty(char *av, t_list **stack)
{
	int	i;

	i = 0;
	if (!av[0])
		print_msg(stack);
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == ' ')
		i++;
	if (!av[i])
		print_msg(stack);
}

void	check_valid(char *av, t_list **stack)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') || av[i] == '+'
			|| av[i] == '-' || av[i] == ' ')
			i++;
		else
			print_msg(stack);
	}
}

void	check_exist(t_list **stack, int res)
{
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->content == res)
		{
			printf("han : %d\n", temp->content);
			print_msg(stack);
		}
		temp = temp->next;
	}
}

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

int	stack_size(t_list **stack_a)
{
	t_list	*ptr;
	int		size;

	size = 0;
	ptr = *stack_a;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}

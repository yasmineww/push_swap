/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:17:26 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/21 12:48:56 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_list	*node1;
	t_list	*node2;
	int		temp;

	node1 = stack;
	node2 = node1->next;
	if (node1 != NULL && node2 != NULL)
	{
		temp = node1->content;
		node1->content = node2->content;
		node2->content = temp;
	}
}

void	rotate(t_list *stack)
{
	t_list	*node1;
	t_list	*node2;
	int		temp;

	node1 = stack;
	temp = node1->content;
	while (stack != NULL)
		stack = stack->next;
	node2 = stack;
	if (node1 != NULL && node2 != NULL)
	{
		node1->content = node2->content;
		node2->content = temp;
	}
}

void	reverse_rotate(t_list *stack)
{
	t_list	*node1;
	t_list	*node2;
	int		temp;

	node1 = stack;
	temp = node1->content;
	while (stack != NULL)
		stack = stack->next;
	node2 = stack;
	if (node1 != NULL && node2 != NULL)
	{
		node1->content = node2->content;
		node2->content = temp;
	}
}
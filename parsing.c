/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:10:01 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/27 13:23:34 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!av[0])
	{
		print_msg();
	}
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == ' ')
	{
		i++;
		if (!av[i])
			print_msg();
	}
}

void	check_valid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') || av[i] == '+'
			|| av[i] == '-' || av[i] == ' ')
			i++;
		else
			print_msg();
	}
}

void	check_exist(t_list *stack, int res)
{
	while (stack != NULL)
	{
		if (stack->content == res)
			print_msg();
		stack = stack->next;
	}
}

void	parse(char **av, t_list **stack_a)
{
	int		i;
	int		res;
	int		j;
	char	**s;

	i = 1;
	while (av[i])
	{
		check_empty(av[i]);
		check_valid(av[i]);
		s = ft_split(av[i], ' ');
		j = 0;
		while (s[j])
		{
			res = my_atoi(s[j]);
			check_exist(*stack_a, res);
			add_back(stack_a, res);
			j++;
		}
		i++;
	}
}

int	check_sort(t_list **stack_a)
{
	t_list	*node1;
	t_list	*node2;

	node1 = *stack_a;
	node2 = node1->next;
	while (node1->next != NULL)
	{
		while (node2 != NULL)
		{
			if (node1->content > node2->content)
				return (1);
			node2 = node2->next; 
		}
		node1 = node1->next;
		node2 = node1->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:06 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/19 01:39:44 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_3(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1 != NULL)
	{
		temp2 = *stack;
		temp1->index_3 = 1;
		while (temp2 != NULL)
		{
			if (temp1->content > temp2->content)
				temp1->index_3 += 1;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	index_4(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1 != NULL)
	{
		temp2 = *stack;
		temp1->index_4 = 1;
		while (temp2 != NULL)
		{
			if (temp1->content > temp2->content)
				temp1->index_4 += 1;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	index_5(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1 != NULL)
	{
		temp2 = *stack;
		temp1->index_5 = 1;
		while (temp2 != NULL)
		{
			if (temp1->content > temp2->content)
				temp1->index_5 += 1;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = stack_size(stack_a);
	if (size == 2 && check_sort(stack_a))
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if ((size == 3) && check_sort(stack_a))
		sort_3(stack_a);
	else if ((size > 3) && check_sort(stack_a))
		algo(stack_a, stack_b);
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
		check_empty(av[i], stack_a);
		check_valid(av[i], stack_a);
		s = ft_split(av[i], ' ');
		j = 0;
		while (s[j])
		{
			res = my_atoi(s[j], stack_a);
			check_exist(stack_a, res);
			add_back(stack_a, res);
			j++;
		}
		i++;
	}
}

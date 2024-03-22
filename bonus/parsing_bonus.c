/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:10:01 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/22 21:13:26 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_exist(t_list **stack, int res, char **s)
{
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->content == res)
		{
			while (*s)
			{
				free(*s);
				s++;
			}
			print_msg(stack);
		}
		temp = temp->next;
	}
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

int	ft_intlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

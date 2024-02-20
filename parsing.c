/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:10:01 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/20 20:16:58 by ymakhlou         ###   ########.fr       */
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

void	check_doubles(t_list *stack, int res)
{
	while (stack != NULL)
	{
		if (stack->content == res)
			print_msg();
		stack = stack->next;
	}
}
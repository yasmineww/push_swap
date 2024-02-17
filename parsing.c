/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:10:01 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/16 19:59:54 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty(char **av)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (av[i])
	{
		if (!av[i][0])//empty string ""
		{
			print_msg();
			//printf("%c", av[i][j]);
		}
		while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == ' ')
			j++;
			if (!av[i][j])
				print_msg();
		i++;
	}
}

void	check_valid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		printf("%c", av[i]);
		if ((av[i] >= '0' && av[i] <= '9') || av[i] == '+'
			|| av[i] == '-' || av[i] == ' ')
				i++;
		else
			print_msg();
	}
}

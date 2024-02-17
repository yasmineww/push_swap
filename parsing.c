/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:10:01 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/17 20:06:16 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty(char *av)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	
		// puts("ok in check empty");
		// printf("letter is --> %c\n", av[i]);
		if (!av[0])//empty string ""
		{
			print_msg();
		}
		while ((av[i] >= 9 && av[i] <= 13) || av[i] == ' ')
			i++;
			if (!av[i])
				print_msg();

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

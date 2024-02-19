/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:05:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/19 11:46:28 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int ac, char **av)
{
	int	i;
	int	res;

	i = 1;
	if (ac == 1)
		return (0);
	else if (ac >= 2)
	{
		while(av[i])
		{
			check_empty(av[i]);
			check_valid(av[i]);
			res = my_atoi(av[i]);
			i++;
		}
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:05:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/23 16:17:07 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			check_exist(stack_a, res, &s[j]);
			add_back(stack_a, res);
			free(s[j]);
			s[j] = NULL;
			j++;
		}
		free(s);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		parse(av, &stack_a);
		sort(&stack_a, &stack_b);
		free_leaks(&stack_a);
		free_leaks(&stack_b);
	}
	return (0);
}

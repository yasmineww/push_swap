/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:05:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/20 18:56:19 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		res;
	int		j;
	char	**s;

	i = 1;
	stack_a = NULL;//declare head
	stack_b = NULL;
	if (ac == 1)
		return (0);
	else if (ac >= 2)
	{
		while (av[i])
		{
			check_empty(av[i]);
			check_valid(av[i]);
			s = ft_split(av[i], ' ');
			j = 0;
			while (s[j])
			{
				res = my_atoi(s[j]);
				check_exist(stack_a, res);
				add_front(&stack_a, res);
				j++;
			}
			i++;
		}
	}
	while (stack_a != NULL) {
       	printf("|%d|\n", (stack_a->content));
        stack_a = stack_a->next;
    }
	return (0);
}

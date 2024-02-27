/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:05:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/26 18:40:58 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;//declare head
	stack_b = NULL;
	if (ac == 1)
		return (0);
	else if (ac >= 2)
		parse(av, &stack_a);
	sort(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
       	printf("|%d|\n", (stack_a->content));
        stack_a = stack_a->next;
    }
	return (0);
}

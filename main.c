/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:05:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/14 22:18:35 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f()
{
	system ("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	//atexit(f);
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	else if (ac >= 2)
		parse(av, &stack_a);
	sort(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
       	printf("content a: |%d|, index : (%d)\n", (stack_a)->content, stack_a->index);
        stack_a = stack_a->next;
    }
	puts("--------------");
	while (stack_b != NULL)
	{
       	printf("content b: |%d|, index : (%d)\n", (stack_b)->content, (stack_b)->index);
        stack_b = stack_b->next;
    }
	return (0);
}

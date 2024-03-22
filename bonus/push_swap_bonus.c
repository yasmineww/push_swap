/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:43:27 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/22 21:13:45 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_leaks(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	do_rot(char *action, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(action, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(action, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(action, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(action, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(action, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(action, "rrr\n") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
	{
		free(action);
		free_leaks(stack_a);
		print_msg(stack_b);
	}
}

void	do_swap(char *action, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(action, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(action, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(action, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
	{
		free(action);
		free_leaks(stack_a);
		print_msg(stack_b);
	}
}

void	apply_actions_bonus(t_list **stack_a, t_list **stack_b)
{
	char	*action;

	action = get_next_line(0);
	while (action)
	{
		if (action[0] == 's')
			do_swap(action, stack_a, stack_b);
		else if (action[0] == 'r')
			do_rot(action, stack_a, stack_b);
		else if (ft_strcmp(action, "pa\n") == 0)
			push(stack_a, stack_b);
		else if (ft_strcmp(action, "pb\n") == 0)
			push(stack_b, stack_a);
		else
		{
			free(action);
			free_leaks(stack_a);
			print_msg(stack_b);
		}
		free(action);
		action = get_next_line(0);
	}
}

// void	f()
// {
// 	system ("leaks checker");
// }

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		parse(av, &stack_a);
		apply_actions_bonus(&stack_a, &stack_b);
		if (check_sort(&stack_a) || stack_b != NULL)
			write(1, "KO\n", 3);
		else if (check_sort(&stack_a) == 0)
			write(1, "OK\n", 3);
		free_leaks(&stack_a);
		free_leaks(&stack_b);
	}
	return (0);
}

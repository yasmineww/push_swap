/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:18:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/19 02:07:22 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_msg(t_list **stack)
{
	write(1, "Error\n", 6);
	free_leaks(stack);
	exit(1);
}

int	ft_strlen(char	*av)
{
	int	count;

	count = 0;
	while (*av)
	{
		count++;
		av++;
	}
	return (count);
}

int	my_atoi(char *str, t_list **stack)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			print_msg(stack);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648 || *str == '-' || *str == '+'
		|| (ft_intlen(res) > 10 && res > 0) || (ft_intlen(res) > 11 && res < 0))
		print_msg(stack);
	return (res);
}

void	add_back(t_list **stack_a, int content)
{
	t_list	*node;
	t_list	*temp;

	node = malloc (sizeof(t_list));
	if (!node)
		return ;
	node->content = content;
	node->next = NULL;
	node->index = 0;
	node->index_3 = 0;
	node->position = 0;
	node->target_cost = 0;
	node->cost = 0;
	node->sum = 0;
	if ((*stack_a) == NULL)
	{
		*stack_a = node;
		return ;
	}
	temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
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

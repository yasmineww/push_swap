/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:18:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/23 22:38:17 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		if (s == NULL)
			return ;
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

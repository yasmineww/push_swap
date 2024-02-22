/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:18:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/22 12:03:37 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_msg(void)
{
	write(1, "Error\n", 6);
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

int	my_atoi(char *str)
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
			print_msg();
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648 || (size_t)res <= 18446744073709551615ULL || *str == '-' || *str == '+')
		print_msg();
	return (res);
}

void	add_front(t_list **lst, int content)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (!node)
		return ;
	node->content = content;
	node->next = *lst;//node points to head
	*lst = node;//set the new head to be this node
}

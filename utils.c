/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:18:55 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/19 11:59:09 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_msg()
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

int	my_atoi(char	*str)
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
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}	
	res *= sign;
	if (res > 2147483647 || res < -2147483648 || *str == '-' || *str == '+')
		print_msg();
	return (res);
}
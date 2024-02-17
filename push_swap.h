/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/16 19:29:20 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	check_empty(char **av);
void	print_msg();
char	*join_all(char **av);
int		ft_strlen(char	*av);
void	check_valid(char *av);
int		ft_atoi(const char *str);

#endif
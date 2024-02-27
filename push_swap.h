/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/26 18:26:39 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	parse(char **av, t_list **stack_a);
void	check_empty(char *av);
void	print_msg(void);
int		ft_strlen(char	*av);
void	check_valid(char *av);
int		my_atoi(char *str);
int		ft_intlen(int n);
void	add_back(t_list **stack_a, int content);
char	**ft_split(char const *s, char c);
void	check_exist(t_list *stack, int res);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);
int		check_sort(t_list **stack_a);
void	sort_3(t_list **stack_a);
void	sort_5(t_list **stack_a, t_list **stack_b);

#endif
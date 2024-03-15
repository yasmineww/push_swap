/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/15 21:00:20 by ymakhlou         ###   ########.fr       */
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
	int				index;
	int				index_3;
	int				position;
	int				target_cost;
	int				cost;
	int				sum;
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
int		stack_size(t_list **stack_a);
void	index_stack(t_list **stack);
void	algo(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	calc_position(t_list **stack);
void	calc_cost(t_list **stack);
void	calc_target(t_list **stack_a, t_list **stack_b);
void	index_3(t_list **stack);
void	best_move(t_list **stack_a, t_list **stack_b);
int		absolute(int cost);
void	apply_actions(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b);
void	rrr(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b);
void	rr(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b);
void	rotate_a(int cost_a, t_list **stack_a);
void	rotate_b(int cost_b, t_list **stack_b);
void	last_sort(t_list **stack_a);
void	compare_elements(t_list *temp1);

#endif
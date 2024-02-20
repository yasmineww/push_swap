/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:18 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/20 18:52:19 by ymakhlou         ###   ########.fr       */
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

void	check_empty(char *av);
void	print_msg(void);
int		ft_strlen(char	*av);
void	check_valid(char *av);
int		my_atoi(char *str);
void	add_front(t_list **lst, int content);
char	**ft_split(char const *s, char c);
void	check_doubles(t_list *stack, int res);

#endif
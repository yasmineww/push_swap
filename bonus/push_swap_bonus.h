/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:22:47 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/03/22 20:57:54 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*read_line(int fd, char *st);
char	*ft_strchr(char *buff, int c);
int		ft_strlen(char *buff);
char	*ft_strjoin(char *stock, char *buff);
int		stock_len(char *stock);
char	*ft_strdup(char *stock);
char	*line_to_return(char *stock);
char	*modify_static(char *stock, char *line);
void	parse(char **av, t_list **stack_a);
void	check_empty(char *av, t_list **stack);
void	check_valid(char *av, t_list **stack);
char	**ft_split(char const *s, char c);
int		my_atoi(char *str, t_list **stack);
void	check_exist(t_list **stack, int res, char **s);
void	add_back(t_list **stack_a, int content);
int		ft_intlen(int n);
void	print_msg(t_list **stack);
int		ft_strcmp(char *s1, char *s2);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
void	free_leaks(t_list **stack);
int		check_sort(t_list **stack_a);
void	do_rot(char *action, t_list **stack_a, t_list **stack_b);
void	do_swap(char *action, t_list **stack_a, t_list **stack_b);

#endif
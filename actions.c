/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:17:26 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/02/22 21:53:24 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	swap(t_list **stack)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*temp;

	node1 = *stack;
	node2 = node1->next;
	if (node1 != NULL && node2 != NULL)
	{
		temp = node1->content;
		node1->content = node2->content;
		node2->content = temp;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	rotate(t_list **stack)
{
	t_list	*old_head;
	t_list	*new_head;
	t_list	*iter;

	old_head = *stack;
	new_head = (*stack)->next;
	old_head->next = NULL;
	iter = new_head;
 	while (iter->next != NULL)
        iter = iter->next;
    iter->next = old_head;
	*stack = new_head;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*old_head;
	t_list	*new_head;
	t_list	*tmp;

	old_head = *stack;
	new_head = *stack;
	tmp = old_head;
 	while (new_head->next != NULL)
        new_head = new_head->next;
	new_head->next = old_head;
	while (tmp != new_head)
		tmp = tmp->next;
	tmp->next = NULL;
	*stack = new_head;
	while (stack != NULL) 
	{
       	printf("|%s|\n", ((*stack)->content));
        stack = &(*stack)->next;
    }
}

int	main (void)
{
	t_list	*head = ft_lstnew("salma");
	t_list	*node1 = ft_lstnew("makh");
	t_list	*node2 = ft_lstnew("yasmine");
	t_list	*node3 = ft_lstnew("makhlouf");
	t_list	*node4 = ft_lstnew("younes");
	t_list	*node5 = ft_lstnew("chaouni");
	t_list	*iter;

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	iter = head;
	reverse_rotate(&head);
	// while (head != NULL) 
	// {
    //    	printf("|%s|\n", (head->content));
    //     head = head->next;
    // }
	// printf("%s\n", head->content);
	// printf("%s\n", node1->content);
	// printf("%s\n", node2->content);
	// printf("%s\n", node3->content);
	// printf("%s\n", node4->content);
	// printf("%s\n", node5->content);
	return (0);
}
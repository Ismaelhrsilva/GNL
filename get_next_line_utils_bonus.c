/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:58:35 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/15 19:10:00 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(1 * sizeof(t_list));
	if (ret == 0)
		return (0);
	ret->content = *(char *)content;
	ret->next = NULL;
	return (ret);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	last = *lst;

	if (*lst == NULL)
		*lst = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		if (current->content != '\n')
			count++;
		else
		{
			count++;
			break ;
		}
		current = current->next;
	}
	return (count);
}

t_array	*ft_verify_and_create_array_list(int fd, t_array **array_list)
{
	t_array	*array_node;
	t_array	*current;

	current = *array_list;
	if (current)
	{
		while (current->next != NULL && current->fd != fd)
			current = current->next;
		if (current->fd == fd)
			return (current);
	}
	array_node = malloc(1 * sizeof(t_array));
	if (array_node == 0)
		return (0);
	array_node->fd = fd;	
	array_node->list = NULL;
	array_node->next = NULL;
	if (current == NULL)
		*array_list = array_node;
	else
		current->next = array_node;
	return (array_node);
}

void	ft_remove_t_array(int fd, t_array **array_list)
{
	t_array	*before;
	t_array *current;

	current = *array_list;
	if (*array_list == NULL)
		return ;
	while (current->next != NULL)
	{
		before = current;
		if (current->fd != fd)
			current = current->next;
		else
		{
			before->next = current->next;
			free(current);
			break ;
		}
	}
	current = NULL;
	before = NULL;
}

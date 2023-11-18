/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:58:35 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/18 18:38:25 by ishenriq         ###   ########.fr       */
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

void	ft_remove_t_array(int fd, t_array **array_list)
{
	t_array	*before;
	t_array	*current;

	current = *array_list;
	before = NULL;
	while (current)
	{
		if (current->fd == fd || fd == -1)
		{
			if (before)
				before->next = current->next;
			else
				*array_list = current->next;
			ft_lstclear(&current->list, -1);
			free(current);
			current = NULL;
		}
		if (fd != -1)
			break ;
		before = current;
		current = current->next;
	}
	current = NULL;
	before = NULL;
}

void	ft_lstclear(t_list **lst, int size)
{
	t_list	*next;
	t_list	*head;

	if (!lst || size == 0)
		return ;
	head = *lst;
	next = *lst;
	if (size == -1)
	{
		while (head)
		{
			head = head->next;
			free(next);
			next = head;
		}
	}
	while (size > 0)
	{
		head = head->next;
		free(next);
		next = head;
		size--;
	}
	*lst = head;
}

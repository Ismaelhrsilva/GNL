/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:48:32 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/06 19:04:49 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
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

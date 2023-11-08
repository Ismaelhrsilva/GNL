/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:19 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/08 19:29:55 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, int size)
{
	t_list	*next;
	t_list	*head;

	if (!lst || size == 0)
		return ;
	head = *lst;
	next = *lst;
	while (size > 0)
	{
		head = head->next;
		//free(&(next->content));
		free(next);
		next = head;
		size--;
	}
	*lst = head;
}

int	ft_construct_list(char *str, t_list **head)
{
	int	i;
	int	out;
	t_list	*content;

	out = 0;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			out = 1;
		content = ft_lstnew(&str[i]);
		ft_lstadd_back(head, content);
		str[i] = '\0';
		i++;
	}
	return (out);
}

char	*ft_build_str(t_list **head)
{
	char	*gnl;
	int	i;
	int	len_list_until_nl;

	len_list_until_nl = ft_lstsize(*head);
	i = 0;
	gnl = calloc(len_list_until_nl + 1, sizeof(char));	
	if (gnl == 0)
		return (0);
	while (len_list_until_nl--)
	{
		gnl[i] = (*head)->content;
		head = &((*head)->next);
		i++;
	}
	gnl[i] = '\0';
	return (gnl);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static t_list	*head;
	int	out;
	int	len;
	char	*str;

	out = 0;
	buffer = calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == 0)
		return (0);
	while (out == 0)
	{
		if (fd < 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		{
			//free(buffer);
			break;
			//return (0);
		}
		if (ft_construct_list(buffer, &head) == 1)
			out = 1;
	}
	len = ft_lstsize(head);
	str = ft_build_str(&head);
	ft_lstclear(&head, len);
	free(buffer);
	return (str);
}

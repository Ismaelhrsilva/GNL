/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:19 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/18 18:37:28 by ishenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static int	ft_construct_list(char *str, t_list **head, int size_line)
{
	int		i;
	int		out;
	t_list	*content;

	out = 0;
	i = 0;
	while (i < size_line)
	{
		if (str[i] == '\n')
			out = 1;
		content = ft_lstnew(&str[i]);
		ft_lstadd_back(head, content);
		i++;
	}
	return (out);
}

static char	*ft_build_str(t_list **head)
{
	char	*gnl;
	int		i;
	int		len_list_until_nl;

	if (!*head)
		return (NULL);
	len_list_until_nl = ft_lstsize(*head);
	i = 0;
	gnl = malloc((len_list_until_nl + 1) * sizeof(char));
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

static int	whiling(int fd, char **buffer, t_list **head, t_array **array_list)
{
	int	out;
	int	read_i;

	out = 0;
	while (out == 0)
	{
		read_i = read(fd, *buffer, BUFFER_SIZE);
		if (read_i < 0)
		{
			ft_remove_t_array(fd, array_list);
			free(*buffer);
			return (0);
		}
		if (read_i == 0)
			break ;
		if (ft_construct_list(*buffer, head, read_i) == 1)
			out = 1;
	}
	return (1);
}

static t_array	*ft_verify_and_create_array_list(int fd, t_array **array_list)
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

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_array	*array_list;
	t_array			*current_fd;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == 0)
		return (0);
	current_fd = ft_verify_and_create_array_list(fd, &array_list);
	if (current_fd == NULL)
		ft_remove_t_array(-1, &array_list);
	if (!whiling(fd, &buffer, &current_fd->list, &array_list))
		return (NULL);
	str = ft_build_str(&current_fd->list);
	if (str == NULL)
		ft_remove_t_array(current_fd->fd, &array_list);
	else
		ft_lstclear(&current_fd->list, ft_lstsize(current_fd->list));
	free(buffer);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:21:26 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/08 19:50:52 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char	content;
	struct s_list	*next;
} t_list;


char	*get_next_line(int fd);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
int	ft_strlen(const char *s, int size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:55 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/13 18:54:56 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	fd = open("1char.txt", O_RDONLY);
	if (fd < 0)
		printf("Erro ao abrir");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
 		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
//	printf("%s", line);
//	if (close(fd) < 0)
//		printf("Erro ao fechar");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:55 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/15 17:52:00 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd_1;
	char	*line;
	int	fd_2;
	int	i;

	fd_1 = open("ler1.txt", O_RDONLY);
	fd_2 = open("ler1.txt", O_RDONLY);
	
	line = get_next_line(fd_1);
	printf("%s", line);
	line = get_next_line(fd_2);
	printf("%s", line);
	line = get_next_line(fd_1);
	printf("%s", line);
	line = get_next_line(fd_2);
	printf("%s", line);
//	if (fd < 0)
//		printf("Erro ao abrir");
//	line = get_next_line(fd);
//	i = 0;
//	while (line)
//	{
// 		printf("%s", line);
//		free(line);
//		line = get_next_line(fd);
//		i++;
//	}
//	printf("%s", line);
//	if (close(fd) < 0)
//		printf("Erro ao fechar");
	return (0);
}

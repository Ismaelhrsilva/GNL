/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:55 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/11 20:04:37 by ishenriq         ###   ########.org.br   */
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
//		if (i == 3)
//			fd = -1;
		line = get_next_line(fd);
		i++;
	}
//	if (close(fd) < 0)
//		printf("Erro ao fechar");
	return (0);
}

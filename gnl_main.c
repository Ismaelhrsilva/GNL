/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishenriq <ishenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:20:55 by ishenriq          #+#    #+#             */
/*   Updated: 2023/11/08 19:55:55 by ishenriq         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	if (fd < 0)
		printf("Erro ao abrir");
	line = get_next_line(fd);
	while (line)
	{
 		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	if (close(fd) < 0)
		printf("Erro ao fechar");
	return (0);
}

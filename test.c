/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:04:30 by ncofre            #+#    #+#             */
/*   Updated: 2021/07/10 20:04:50 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd;

	line = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("An error ocurred while opening the fd");
		return (-1);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:04:30 by ncofre            #+#    #+#             */
/*   Updated: 2021/04/24 08:25:55 by ncofre           ###   ########.fr       */
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
	int ret;

	line = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("An error ocurred while opening the fd");
		return (-1);
	}
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		printf("%s", line);
	}
	printf("\n");
	printf("%i\n", ret);
	free(line);
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openreadprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:18:10 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 23:18:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*line;

	line = malloc(70 * sizeof(char));
	read(fd, line, 70);
	if (!line )
		return (NULL);
	return (line);
}

int main(void)
{
	int		fd;

	fd = open("base.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	return 0;
}
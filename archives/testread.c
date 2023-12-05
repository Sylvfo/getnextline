/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:58:34 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 19:58:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*buffer;
	char	*line;

	buffer = malloc(25 * sizeof(char));
	line = malloc(10 * sizeof(char));
	fd = open("test.txt", O_RDWR);
	read(fd, buffer, 2);
	read(fd, line, 3);
	printf("%s\n", buffer);
	printf("%s\n", line);
	return (0);
}

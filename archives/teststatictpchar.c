/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teststatictpchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:28:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/04 10:37:32 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*stattochar(void)
{
	static  char  *base = "ab";
	return (base);
}

int	main(void)
{
	printf("%s\n", stattochar());
}
/*
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
*/
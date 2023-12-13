/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/13 00:59:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int	ft_findline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_get_line_reminder(char **line)
{
	size_t		i;
	char		*reminder;
	char		*next_line;

	i = 0;
	if (!*line)
		return (NULL);
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		i++;
	if (!(*line)[i])
		reminder = NULL;
	else
		reminder = ft_strndup(*line + i, ft_strlen(*line + i));
	next_line = ft_strndup(*line, i);
	free (*line);
	*line = reminder;
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char		*reminder = NULL;
	char			buff[BUFFER_SIZE + 1];
	size_t			bytesread;


	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || 1024 < fd )
		return (NULL);
	if (reminder && ft_findline(reminder) == 1)
		return (ft_get_line_reminder(&reminder));
	bytesread = read(fd, buff, BUFFER_SIZE);
	buff[bytesread] = 0;
	while (bytesread > 0 && bytesread <= BUFFER_SIZE)
	{
		reminder = ft_strjoin(reminder, buff);
		if (!reminder || ft_findline(reminder) == 1)
			return (ft_get_line_reminder(&reminder));
		bytesread = read(fd, buff, BUFFER_SIZE);
		buff[bytesread] = 0;
	}
	return ft_get_line_reminder(&reminder);
}
/*
int	main(void)
{
	int		fd;
	char	*line = NULL;

	fd = open("base.txt", O_RDONLY);
//        return 0;
	printf("%s fin1++\n", (get_next_line(fd)));
	line = get_next_line(fd);
	printf("%sfin2++\n", line);
	line = get_next_line(fd);
	printf("%sfin3++\n", line);
	line = get_next_line(fd);
	printf("%sfin4++", line);
	line = get_next_line(fd);
	printf("%sfin5++", line);
	line = get_next_line(fd);
	printf("%s++", line);
	free(line);
	close (fd);
	return (0);
}*/

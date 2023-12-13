/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:11:09 by marvin            #+#    #+#             */
/*   Updated: 2023/12/13 00:11:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s, size_t c)
{
	size_t		i;
	char	*dest;
	size_t		j;

	if ((int)c < ft_strlen(s))
		j = c;
	else
		j = ft_strlen(s);
	dest = (char *)malloc(j + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < j && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		s1i;
	int		s2i;

	s1i = 0;
	s2i = 0;
	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[s1i])
	{
		dst[s1i] = (char)s1[s1i];
		s1i++;
	}
	while (s2[s2i])
	{
		dst[s1i] = (char)s2[s2i];
		s1i++;
		s2i++;
	}	
	dst[s1i] = '\0';
	free (s1);
	return (dst);
}

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

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || 4095 < fd)
		return (NULL);
	if (reminder && ft_findline(reminder) == 1)
		return (ft_get_line_reminder(&reminder));
	bytesread = read(fd, buff, BUFFER_SIZE);
	buff[bytesread] = 0;
	while (bytesread > 0)
	{
		reminder = ft_strjoin(reminder, buff);
		if (!reminder || ft_findline(reminder) == 1)
			return (ft_get_line_reminder(&reminder));
		bytesread = read(fd, buff, BUFFER_SIZE);
		buff[bytesread] = 0;
	}
	return ft_get_line_reminder(&reminder);
}

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
}
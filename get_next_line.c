/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/05 11:55:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_n_find(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_stash_to_line(char *line, char *stash, int sizest)
{
	int		i;
	int		j;
	char	*new_line;

	new_line = malloc((ft_strlen(line) + sizest + 3) *(sizeof(char)));
	if (!new_line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (j < sizest)
	{
		new_line[i] = stash[j];
		i++;
		j++;
	}
	i++;
	new_line[i] = 0;
	return (new_line);
}

int	ft_read_stash(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (-1);
	while (stash[i] != '\n' || stash[i] != 0)
	{
		i++;
	}
	i++;
	return (i);
}

char	*ft_clean_stash(char *stash, int lg_line)
{
	void	*new_stash;

	new_stash = ft_substr(stash, lg_line, ft_strlen(stash) - lg_line);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*new_line;
	int			sizeb;
	int			bytesRead;

	new_line = malloc(BUFFER_SIZE * sizeof(char));
	new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
//	if (!new_line)
//		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
//	if (buff)
//		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
//	buff = malloc(BUFFER_SIZE * sizeof(char));
//	if (!buff)
//		return (NULL);
	while (ft_n_find(buff) < 1)
	{
		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
		bytesRead = read(fd, buff, BUFFER_SIZE);
		if (bytesRead <= 0)
		{
			free(new_line);
			free(buff);
			return (NULL);
		}
	}
	
//	if (buff == '\0')
//		return (new_line);
	sizeb = ft_read_stash(buff);
	new_line = ft_stash_to_line(new_line, buff, sizeb);
	buff = ft_clean_stash(buff, sizeb);
	return (new_line);
	free (new_line);
}


int main(void)
{
	int		fd;
	char	*line;

	fd = open("base.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s++", line);
//	line = get_next_line(fd);
//	printf("%s++", line);
	free(line);
	close (fd);
	return 0;
}

/*
int main(void)
{
	int		fd;
	char	*line;

	fd = open("base.txt", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	close (fd);
	return 0;
}
*/


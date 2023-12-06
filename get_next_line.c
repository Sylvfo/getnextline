/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/06 12:35:34 by marvin           ###   ########.fr       */
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
		if (str[i] == '\n' || str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_read_stash(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i]!= '\n' || stash[i] != 0)
			break;
		i++;
	}
	return (i);
}

char	*ft_stash_to_line(char *line, char *stash, int sizest)
{
	int		i;
	int		j;
	char	*new_line;

	new_line = malloc((ft_strlen(line) + sizest + 2) *(sizeof(char)));
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
//	i++;
//	new_line[i] = 0;
	return (new_line);
}



char	*ft_clean_stash(char *stash, int lg_line)
{
	void	*new_stash;

	new_stash = ft_substr(stash, lg_line, (ft_strlen(stash) - lg_line));
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*new_line;
	int				sizeb;
	int				bytesRead;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	new_line = malloc(BUFFER_SIZE * sizeof(char*));
	if (!new_line)
		return (NULL);
	if (buff != 0)
		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	while(ft_n_find(buff) != 1 && bytesRead > 0)
	{
		bytesRead = read(fd, buff, BUFFER_SIZE);
		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
	}
	sizeb = ft_read_stash(buff);
	new_line = ft_stash_to_line(new_line, buff, sizeb);
	buff = ft_clean_stash(buff, sizeb);
	if (bytesRead < 1)
	{
		free(new_line);
		free(buff);
		return (0);
	}
	return (new_line);
}
//	getchar();
//	if (buff)
//		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
//	
//	getchar();
//	if (!new_line)
//		return (NULL);
	
//	
//		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
//	while (ft_n_find(buff) < 1)
//	{
//		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
//		bytesRead = read(fd, buff, BUFFER_SIZE);
//		if (bytesRead <= 0)
//			break ;
//	}
//	if (buff == '\0')
//		return (new_line);
/*
	sizeb = ft_read_stash(buff);
	new_line = ft_stash_to_line(new_line, buff, sizeb);
	buff = ft_clean_stash(buff, sizeb);
	free (new_line);
	return (new_line);
}*/

int main(void)
{
	int		fd;
	char	*line;
	fd = open("base.txt", O_RDONLY);
 //       return 0;
	line = get_next_line(fd);
	printf("%sfin1++\n", line);
	line = get_next_line(fd);
	printf("%sfin2++\n", line);
	line = get_next_line(fd);
	printf("%sfin3++\n", line);
	line = get_next_line(fd);
	printf("%s++", line);
	free(line);
	close (fd);
	return 0;
}
/*
int main(void)
{
	int		fd;

	fd = open("base.txt", O_RDONLY);
//	get_next_line(fd);
	printf("%s", get_next_line(fd));
//	line = get_next_line(fd);
//	printf("%s++", line);
//	free(line);
	close (fd);
	return 0;
}
*/
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


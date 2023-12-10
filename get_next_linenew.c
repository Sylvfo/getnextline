/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linenew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/10 15:10:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*int	ft_n_find(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		if (str[i] == '\0')
			return (2);
		i++;
	}
	return (0);
}*/
/*
int	ft_read_stash(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\n' && stash[i])
	{
		i++;
	}
	return (i);
}*/

/*char	*ft_stash_to_line(char *line, char *stash, int sizest)
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
}*/
char	*ft_read_add_buff(fd, buff)
{
	int		bytesread;
	char	*new_buff;
	
	new_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!new_buff)
		return (NULL);
	bytesread = 1;
// pas encore tres sure comment est géré ce probleme de buffer pas vide...
	while ((ft_strchr(buff, '\n') == 0) && bytesread != 0)
	{
		bytesread = read("base2.txt", buff, BUFFER_SIZE);
		buff[bytesread] = '\0';
		new_buff = ft_strjoin(new_buff, buff);
	}
	free (buff);
	return (new_buff);
}

char	*ft_buff_to_line(char *buff)
{
	int		i;
	int		j;
	char	*new_line;

	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (buff[j] && j < i)
	{
		new_line[j] = buff[j];
		j++;
	}
	new_line[j] = '\n';
	return (new_line);
}

char	*ft_clean_buff(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *) s + i + 1);
		i++;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*new_line;
//	int				bytesRead;
//	int				found;

//	found = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = ft_read_add_buff(fd, buff);
// il sort d ici avec le \n moustique dans le filet à papillon. 
// en fait tu utilises le filet pour attraper plus de papillon jusque ya un moustique. 
	if (!buff)
		return (NULL);
	new_line = ft_buff_to_line(buff);
	buff = ft_clean_buff(buff);
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
//        return 0;
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
	if (buff)
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
	if (bytesRead <= 0)
	{
		free(new_line);
		free(buff);
		return (0);
	}
	return (new_line);
}
*/


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/11 12:34:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_add_buff(int fd, char *buff)
{
	int		bytesread;
	char	*new_buff;

	new_buff = malloc((BUFFER_SIZE) * sizeof(char));
	if (!new_buff)
		return (NULL);
	bytesread = 1;
// pas encore tres sure comment est gér ce probleme de buffer pas vide...
//&& !ft_strchr(buff, '\0')
	while (!ft_strchr(buff, '\n') && bytesread > 0 && !ft_strchr(buff, '\0'))
	{
		new_buff = ft_strjoin(new_buff, buff);
		bytesread = read(fd, buff, BUFFER_SIZE);
		buff[bytesread] = '\0';
	}
	if (bytesread == 0)
		return (NULL);
	new_buff = ft_strjoin(new_buff, buff);
	free (buff);
//	if (!new_buff)
//		return (NULL);
	return (new_buff);
}

char	*ft_buff_to_line(char *buff)
{
	int		i;
	int		j;
	char	*line;

	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	while (buff[i])
	{
//		if (buff[i] == '\n' || buff[i] == '\0')
		if (buff[i] == '\n')
			break ;
		i++;
	}
	if (i == 0)
		return (NULL);
	line = malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	while (i >= j)
	{
		line[j] = buff[j];
		j++;
	}
	j++;
	line[j] = '\0';
	return (line);
}

char	*ft_clean_buff(char *buff)
{
	int		i;
	int		j;
	char	*new_buff;

	
	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	while (buff[i])
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			break ;
		i++;
	}
	i++;
	i++;
	new_buff = malloc((ft_strlen(buff) - i -1) * sizeof(char));
	if (!new_buff)
		return (NULL);
	while (buff[i])
	{
		new_buff[j] = buff[i];
		j++;
		i++;
	}
	j++;
	new_buff[j] = '\0';
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*line;
	char			*gg;
	int				bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) <= 0 || 4095 < fd)
		return (NULL);
	if (line && ft_findline(line) == 1)
		return (ft_buff_to_line(line));
	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	bytesread = read(fd, buff, BUFFER_SIZE);
	buff[bytesread] = '\0';
	while (bytesread > 0)
	{
		line = ft_strjoin(line, buff);
		if (ft_findline (line) == 1)
			break ;
		bytesread = read(fd, buff, BUFFER_SIZE);
		buff[bytesread] = '\0';
	}
//	return (line);
	gg = ft_buff_to_line(line);
//	return (gg);
	line = ft_clean_buff(line);
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
//		return (buff);
/*	if (line[0] == '\0')
	{
		free (buff);
		return (NULL);
	}*/
//		return (line);
	return (gg);
}
/*
int	main(void)
{
	int		fd;
	char	*line = NULL;

	fd = open("base2.txt", O_RDONLY);
//        return 0;
	line = get_next_line(fd);
	printf("%sfin1++\n", line);
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

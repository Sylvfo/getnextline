/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/11 00:29:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_add_buff(int fd, char *buff)
{
	int		bytesread;
	char	*new_buff;
	
	new_buff = malloc((BUFFER_SIZE) * sizeof(char));
	if(!new_buff)
		return (NULL);
	bytesread = 1;
// pas encore tres sure comment est gér ce probleme de buffer pas vide...
//&& !ft_strchr(buff, '\0')
	while (!ft_strchr(buff, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buff, BUFFER_SIZE);
		buff[bytesread] = '\0';
		new_buff = ft_strjoin(new_buff, buff);
	}
//	if (bytesread == 0)
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
	char	*new_line;

	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (buff[j] && j <= i )
	{
		new_line[j] = buff[j];
		j++;
	}
	j++;
	new_line[j] = 0;
	return (new_line);
}

char	*ft_clean_buff(char *buff)
{
	int		i;
	int		j;
	char	*new_buff;

	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	new_buff = malloc(ft_strlen(buff) - i * sizeof(char));
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
	static char		*buff;
	char			*new_line;


	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0 || 4095 < fd)
		return (NULL);
	if (!buff)
	{
		buff = malloc(BUFFER_SIZE * sizeof(char));
		if (!buff)
			return (NULL);
		read(fd, buff, BUFFER_SIZE);
	}
	buff = ft_read_add_buff(fd, buff);
//		return (buff); 
	new_line = ft_buff_to_line(buff);
//		return (new_line);
//		return (buff);
	buff = ft_clean_buff(buff);
		return (buff);
//	return (new_line);
}

int main(void)
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
	return 0;
}



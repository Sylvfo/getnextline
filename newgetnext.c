/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgetnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:39:20 by sforster          #+#    #+#             */
/*   Updated: 2023/12/04 19:22:05 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 50
# endif

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(s + start))
		len = (size_t)ft_strlen(s + start);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[(size_t)start + i];
		i++;
	}
	return (dst);
}

int	ft_n_find(char *str)
{
	int	i;

	if(!str)
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

char	*ft_stash_to_line(char *line, char *stash, int sizest)
{
	int 	i;
	int		j;
	char	*new_line;

	new_line = malloc((ft_strlen(line) + sizest + 1) *(sizeof(char)));
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
	return(new_line);
}

int	ft_read_stash(char *stash)
{ 
	int	i;

	i = 0;
	if (!stash)
		return (-1);
	while (stash[i] != '\n' && stash[i] != 0)
	{
		i++;
	}
	i++;
	return(i);
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

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (buff != 0)
		 new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
	else
		buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
		new_line = malloc(BUFFER_SIZE + 1 * sizeof(char));
	
	while (ft_n_find(buff) == 0)
	{
		new_line = ft_stash_to_line(new_line, buff, BUFFER_SIZE);
		read(fd, buff, BUFFER_SIZE);
	}
	if (!buff)
		return (0);
	sizeb = ft_read_stash(buff);
	new_line = ft_stash_to_line(new_line, buff, sizeb);
	buff = ft_clean_stash(buff, sizeb);
	return (new_line);
}

int main(void)
{
	int		fd;
//	char	*line;

	fd = open("test.txt", O_RDONLY);
//	line = get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
//	line = get_next_line(fd);
//	printf("%s++", line);
//	free(line);
	close (fd);
	return 0;
}
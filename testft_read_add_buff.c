/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft_read_add_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:45:12 by marvin            #+#    #+#             */
/*   Updated: 2023/12/10 12:45:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
// ajout 2 lignes
	if (!str)
		return(0);
	while (str[i])
		i++;
	return (i);
}

//different....
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
//ajout 2 lignes...
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *) s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
// ici ça gere le probleme s il y a un buffer ou pas. 
	if (!s1)
		return (char *)(s2);
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	dst = (char *)malloc((j + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = (char)s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dst[j] = (char)s2[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_read_add_buff(int fd, char *buff)
{
	int		bytesread;
	char	*new_buff;
	
	new_buff = malloc((BUFFER_SIZE + 2) * sizeof(char));
	if(!new_buff)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(new_buff, '\n')&& bytesread != 0)
	{
		bytesread = read(fd, new_buff, BUFFER_SIZE);
		new_buff[bytesread] = '\0';
		buff = ft_strjoin(buff, new_buff);
	}
	free(new_buff);
	return (buff);
}

int	main(void)
{
	int		fd;
	char	*line = "";

	fd = open("base.txt", O_RDONLY);
	printf("%s", ft_read_add_buff(fd, line));
	printf("%s", ft_read_add_buff(fd, line));
	close(fd);
	return (0);
}
/*
int	main(void)
{
	int		fd;
	char	*line = "";

	fd = open("base.txt", O_RDONLY);
	printf("%s", ft_read_add_buff(fd, line));
	close(fd);
	return (0);
}*/
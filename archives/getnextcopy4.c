/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextcopy4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:01:50 by sforster          #+#    #+#             */
/*   Updated: 2023/12/04 18:38:58 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//CELUI LAAAA
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "get_next_line.h"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 5
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

//A lire -> \n dans filet a papillon ou \0
//bien regarder si null ou pas (fichier vide)
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
	return(i);
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
	while (stash[j])
	{
		new_line[i] = stash[j];
		i++;
		j++;
	}
	return(new_line);
}

//add the content of our buffer to the end of our stash
char	*ft_clean_stash(char *stash, int lg_line)
{
	void	*new_stash;

	new_stash = ft_substr(stash, lg_line, ft_strlen(stash));
	return (new_stash);
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

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			sizest;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, stash, BUFFER_SIZE);
	line = ft_stash_to_line(line, stash, BUFFER_SIZE);
//	if (!stash)
//		stash = malloc(BUFFER_SIZE + 1 * sizeof(char));
//	if (stash)
//		line = ft_stash_to_line(line, stash, BUFFER_SIZE);
	
//	while (ft_n_find(stash) < 1)
//	{
//		read(fd, stash, BUFFER_SIZE);
//		line = ft_stash_to_line(line, stash, BUFFER_SIZE);
//	}
//	read(fd, stash, BUFFER_SIZE);
//	sizest = ft_read_stash(stash);
//	line = ft_stash_to_line(line, stash, sizest + 1);
//	ft_strlcat(line, stash, sizest);
//	line = ft_stash_to_line(line, stash, sizest + 1);
//	stash = ft_clean_stash(stash, sizest);
	return (line);
}

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
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
	while (1)
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
/*
1 fonction get next line
erreur pas de fichier, ficher non readable, buffer size < 0

appeler 3 fonctions

A lire -> \n dans filet a papillon ou \0
bien regarder si null ou pas (fichier vide)
return null

B extracteur tous caracteres dans une line (resultat)
strjoin (y compris malloc)
mettre les papillons dans la serre. 

C line remover supprimer ce qu on vient d extraire pour supprimer dans variable statique
petits papillons dans nouvelle serre. 

utilser malloc pour 

bonus facile???
tableau de buffer avec index fd. 
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:01:50 by sforster          #+#    #+#             */
/*   Updated: 2023/12/01 19:09:31 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//CELUI LAAAA
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	*stash = 0;
	char		*line;
	int			sizest;

	line = NULL;
	stash = malloc(sizeof(BUFFER_SIZE + 1));
	read(fd, stash, BUFFER_SIZE);
//erreur pas de fichier, ficher non readable, buffer size < 0
	if (!fd || BUFFER_SIZE < 0)
		return (NULL);
	sizest = ft_read_stash(stash);
	ft_stash_to_line(line, stash, sizest);
//	si pas dre\n ajouter stash a line. 
//	Sinon ajouter juste les lettres avant le /n et retourner la taille
	stash = ft_clean_stash(stash);

	return (line);
}
//A lire -> \n dans filet a papillon ou \0
//bien regarder si null ou pas (fichier vide)
return null
int	ft_read_stash(void *stash)
{ 
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' || stash[i] != 0)
	{
		i++;
	}
	return(i);
}

void	*ft_stash_to_line(char *line, char *stash, int sizest)
{
	int 	i;
	void	*tmp;

	tmp = malloc(sizet + 1 *(sizeof(int)));

	i = 0;
	while (i > sizest)
	{
		tmp[i] = stash[i];
		i++;
	}
	char	*stash 
	while(stash(sizet))
	{
		strjoin
	}
	return(line);
}

}

//add the content of our buffer to the end of our stash
void	*ft_clean_stash(void *stash, BUFFER_SIZE, int lg_line)
{
	void	*new_stash;
	int		i;

	i = 0;
	new_stash = malloc(sizeof(BUFFER_SIZE + 1));
	while (new_stash[i])
	{
		new_stash[i] = 
	}
	return (new_stash);
}

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
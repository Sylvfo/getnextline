/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:01:50 by sforster          #+#    #+#             */
/*   Updated: 2023/12/01 12:01:51 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;

	
}
//use read to add characteres to the stash */
void	read_and_stash()
{

}

//add the content of our buffer to the end of our stash
void	add_to_stash()
{

}

//extract all characters from our stash and stores them in out line.
// stop after the first \n encouters. 
void	extract_line()

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
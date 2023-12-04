/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teststashtoline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:10:23 by sforster          #+#    #+#             */
/*   Updated: 2023/12/04 18:09:46 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	new_line[i] = '\0';
	return(new_line);
}

int main(void)
{
	char	*line1 = "JOhoo ";
	char	*stash2 = "Kiaa!";

	printf("%s", ft_stash_to_line(line1, stash2, 3));
	return (0);
}
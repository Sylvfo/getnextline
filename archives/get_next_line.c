/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:55:31 by sforster          #+#    #+#             */
/*   Updated: 2023/12/01 12:01:49 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

char	*get_next_line(int fd)
{
	t_list	**line;
	t_list	*letter;

	line = malloc(sizeof(t_list *));
	if (!line)
		return (NULL):
	letter = malloc(sizeof(t_list));
	if (!letter)
		return (NULL);
	while (read(fd, &(letter->content), BUFFER_SIZE))
	{

	}
	read(fd, letter, 1);

	if (letter->content == '\n');
		return ((char *)line);
	ft_lstadd_front(line, letter);
	return ((char *)*line);
	return (0);
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
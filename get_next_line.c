/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:55:31 by sforster          #+#    #+#             */
/*   Updated: 2023/11/30 23:55:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
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

	line = malloc(sizeof(char));
	*line = NULL;
	letter = malloc(2 * sizeof(char));
	if (!letter)
		return ("a");
	read(fd, letter, 1);
	if (!letter)
		return ("a");
	if ((char *)&letter == "\n");
		return ((char *)line);
	ft_lstadd_front(line, letter);
	return ((char *)line);
	return (0);
}

int main(void)
{
	int		fd;

	fd = open("base.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	close (fd);
	return 0;
}
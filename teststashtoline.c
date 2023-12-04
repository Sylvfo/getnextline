/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teststashtoline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:10:23 by sforster          #+#    #+#             */
/*   Updated: 2023/12/04 11:55:56 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_stash_to_line(char *stash, int sizest)
{
	int 	i;
	void	*new_line;

	tmp = malloc(sizest + 1 *(sizeof(char)));
	i = 0;
	while (i < sizest)
	{
		tmp[i] = stash[i];
		i++;
	}
	return(tmp);
}
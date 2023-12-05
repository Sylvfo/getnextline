/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testftstashtoline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:30:40 by marvin            #+#    #+#             */
/*   Updated: 2023/12/05 21:30:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

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
	int		i;
	int		j;
	char	*new_line;

	new_line = malloc((ft_strlen(line) + sizest + 1) *(sizeof(char)));
	if (!new_line)
		return (NULL);
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
	i++;
	new_line[i] = 0;
	return (new_line);
}

int main(void)
{
	char	*one = "lalala";
	char	*two = " let the sun shine";

	printf("%s\n", ft_stash_to_line(one, two, 8));
	printf("%d", ft_strlen(one));
	return (0);
}
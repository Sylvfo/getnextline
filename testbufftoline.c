/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbufftoline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:59:57 by marvin            #+#    #+#             */
/*   Updated: 2023/12/10 23:59:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif


char	*ft_buff_to_line(char *buff)
{
	int		i;
	int		j;
	char	*new_line;

	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	new_line = malloc((i) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (buff[j] && j <= i)
	{
		new_line[j] = buff[j];
		j++;
	}
	new_line[j - 1] = '\0';
	return (new_line);
}

int main(void)
{
	char *str = "seul le soir \n tard..-";
	printf("%s", ft_buff_to_line(str));
	return (0);
}



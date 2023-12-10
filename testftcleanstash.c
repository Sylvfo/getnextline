/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testftcleanstash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:26 by marvin            #+#    #+#             */
/*   Updated: 2023/12/10 14:52:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_clean_buff(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *) s + i + 1);
		i++;
	}
	return (s);
}

/*
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
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (buff[j] && j < i)
	{
		new_line[j] = buff[j];
		j++;
	}
	new_line[j] = '\n';
	return (new_line);
}
*/

int	main(void)
{
	char	*kaa = "";
			
	printf("%s", ft_clean_buff(kaa));
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:44:00 by sforster          #+#    #+#             */
/*   Updated: 2023/12/13 18:16:31 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s, size_t c)
{
	size_t		i;
	char	*dest;
	size_t		j;

 //	if (!s)
//		return (NULL);
	if (c < ft_strlen(s))
		j = c;
	else
		j = ft_strlen(s);
	dest = (char *)malloc(j + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < j && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char		*dst;
	size_t		s1i;
	size_t		length;
	char		*s;


	s = s1;
	s1i = 0;
	length = ft_strlen(s1);
	if (ft_strlen(s2))
		length += ft_strlen(s2);
	dst = malloc((length + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (s1)
		while (*s1)
			dst[s1i++] = *(s1++);
	if (s2)
		while (*s2)
			dst[s1i++] = (*s2++);
	dst[s1i] = '\0';
	free (s);
	return (dst);
}

void	*ft_bzero(void *s, int n)
{
	unsigned char	*p;
	int			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
	return (s);
}
void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*p;
	int			i;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (b);
}

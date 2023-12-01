/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:44:00 by sforster          #+#    #+#             */
/*   Updated: 2023/12/01 18:52:23 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	dst = (char *)malloc((j + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = (char)s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dst[j] = (char)s2[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
/*
int main(void)
{
	char	*str1 = "oooh ";
	char	*str2 = "yeaaah";
	char	*str3;
	char	*str4 = "babyy";

	printf("%s\n", ft_strjoin(str1, str2));
	str3 = ft_strjoin(str1, str2);
	printf("%s\n", str3);
	str4 = ft_strjoin(str3, str1);
	printf("%s\n", str4);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:15:56 by sforster          #+#    #+#             */
/*   Updated: 2023/12/04 08:29:48 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>

static int	wordcount(char const *s, char c);
static char	*ft_word(const char *str, int start, int end);
static void	ft_initiate_vars(int *i, int *j, int *s_word);
static void	*ft_free(char **tbl, int count);

//strlen
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//calloc
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

//split
static int	wordcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static void	ft_initiate_vars(int *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

static char	*ft_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(((end - start) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = (char)str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **tbl, int co)
{
	int	i;

	i = 0;
	while (i < co)
	{
		free(tbl[i]);
		i++;
	}
	free(tbl);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		s_word;
	char	**tab;

	ft_initiate_vars(&i, &j, &s_word);
	tab = ft_calloc((wordcount(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			tab[j] = ft_word(s, s_word, i);
			if (!(tab[j]))
				return (ft_free(tab, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (tab);
}
/*
int	main(void)
{
	char const	*str = "Starway \n to heaven";
	char		c = '\n';
	char 		**temp;

	temp = ft_split(str, c);
	printf("%s ++ %s", temp[0], temp[1]);
	return (0);
}
*/
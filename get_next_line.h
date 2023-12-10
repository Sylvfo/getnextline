/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:55:21 by sforster          #+#    #+#             */
/*   Updated: 2023/12/10 12:36:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_n_find(char *str);
char	*ft_stash_to_line(char *line, char *stash, int sizest);
int		ft_read_stash(char *stash);
char	*ft_clean_stash(char *stash, int lg_line);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
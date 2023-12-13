static char	*get_line(char **s)
{
	size_t	l;
	char	*next_line;
	char	*reminder;

	l = 0;
	if (!*s)
		return (NULL);
	while ((*s)[l] && (*s)[l] != '\n')
		l++;
	if ((*s)[l] == '\n')
		l++;
	if (!(*s)[l])
		reminder = NULL;
	else
		reminder = ft_strndup(*s + l, ft_strlen(*s + l));
	next_line = ft_strndup(*s, l);
	free(*s);
	*s = reminder;
	return (next_line);
}
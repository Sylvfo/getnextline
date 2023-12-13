static char	*ft_get_line_reminder(char **line)
{
	size_t		i;
	char	*next_line;
	char	*reminder;
	
	i = 0;
	if (!*line)
		return (NULL);
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		i++;
	if (!(*line)[i])
		reminder = NULL;
	else
		reminder = ft_strndup(*line + i, ft_strlen(*line + i));
	next_line = ft_strndup(*line, i);
	free (*line);
	*line = reminder;
	return (next_line);
}



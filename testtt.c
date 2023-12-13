char	*get_next_line(int fd)
{
//	char			buff[BUFFER_SIZE + 1];
	static char		*reminder = NULL;
	int				bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) <= 0)
		return (NULL);
	if (reminder && ft_findline(reminder) == 1)
		return (ft_get_line_reminder(&reminder));
	bytesread = read(fd, buff, BUFFER_SIZE);
	buff[bytesread] = '\0';
	while (0 < bytesread  && bytesread <= BUFFER_SIZE)
	{
		reminder = ft_strjoin(reminder, buff);
		if (!reminder || ft_findline(reminder))
			return ft_get_line_reminder(&reminder);
		bytesread = read(fd, buff, BUFFER_SIZE);
		buff[bytesread] = '\0';
	}
	return (ft_get_line_reminder(&reminder));
}

char	*get_next_line(int fd)
{
	static char	*newl = NULL;
//	char		buffer[BUFFER_SIZE + 1];
	size_t		n;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || 4095 < fd )
		return (NULL);
// si ya dj qqch dans le buff et que ya /n dedans
	if (newl && ft_hasline(newl))
		return (get_line(&newl));
// lit la taille de buffer size et met dans buffer. 
	n = read(fd, buffer, BUFFER_SIZE);
	buffer[n] = 0;
//debut boucle
//while (0 < n && n <= BUFFER_SIZE)
	while (0 < n)
	{
		newl = ft_strjoin(newl, buffer);
		if (!newl || ft_hasline(newl))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
	}
	return (get_line(&newl));
}
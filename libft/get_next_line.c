/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 23:13:27 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 17:10:46 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join(char *buffer, char *other)
{
	char	*tmp;

	tmp = buffer;
	buffer = ft_strjoin(tmp, other);
	free(tmp);
	return (buffer);
}

static char	*ft_free(char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

static char	*ft_reading(int fd, char *buffer)
{
	char		*tmp;
	ssize_t		readed;

	if (!buffer)
		buffer = ft_strdup("");
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_free(buffer));
	while (buffer && !ft_strchr(buffer, '\n'))
	{
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed < 0)
			return (ft_free(buffer), ft_free(tmp));
		if (readed == 0)
		{
			if (buffer[0] == '\0')
				return (ft_free(tmp), buffer);
			break ;
		}
		tmp[readed] = '\0';
		buffer = join(buffer, tmp);
		if (!buffer)
			return (ft_free(buffer));
	}
	return (ft_free(tmp), buffer);
}

static char	*ft_nl(char **buffer)
{
	char	*line;
	char	*newline;
	char	*remaining;

	if (!buffer || !*buffer)
		return (NULL);
	newline = ft_strchr(*buffer, '\n');
	if (newline)
	{
		line = ft_substr(*buffer, 0, newline - *buffer + 1);
		remaining = ft_strdup(newline + 1);
		free(*buffer);
		*buffer = remaining;
		if (!line)
			return (ft_free(line), ft_free(remaining));
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffers[fd] = ft_reading(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = ft_nl(&buffers[fd]);
	if (line && line[0] == '\0')
		return (ft_free(line));
	if (buffers[fd] && buffers[fd][0] == '\0')
	{
		ft_free(buffers[fd]);
		buffers[fd] = NULL;
	}
	return (line);
}

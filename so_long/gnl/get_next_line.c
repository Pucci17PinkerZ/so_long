/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfiora-d <nfiora-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:57:53 by nfiora-d          #+#    #+#             */
/*   Updated: 2025/10/22 13:00:47 by nfiora-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_open(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0644);
	if (!fd)
	{
		perror("open");
		return (1);
	}
	return (fd);
}

static char	*ft_clean_and_return(char *line, int nbread)
{
	if (nbread < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*ft_readfile(int fd, char *line)
{
	char	*buff;
	char	*tmp;
	int		nbread;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbread = 1;
	while (nbread > 0 && ft_checkstr(line) < 0)
	{
		nbread = read(fd, buff, BUFFER_SIZE);
		if (nbread <= 0)
			break ;
		buff[nbread] = '\0';
		tmp = line;
		line = ft_strjoin(line, buff);
		if (tmp)
			free(tmp);
	}
	free(buff);
	return (ft_clean_and_return(line, nbread));
}

static char	*ft_extractline(char **line)
{
	char	*tmp;
	char	*extract;
	int		i;
	int		len;

	if (!*line || !**line)
		return (NULL);
	i = ft_checkstr(*line);
	if (i >= 0)
	{
		extract = ft_strndup(*line, i + 1);
		len = ft_strlen(*line) - (i + 1);
		if (len > 0)
			tmp = ft_strndup(*line + i + 1, len);
		else
			tmp = NULL;
		free(*line);
		*line = tmp;
		return (extract);
	}
	extract = ft_strndup(*line, ft_strlen(*line));
	free(*line);
	*line = NULL;
	return (extract);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_readfile(fd, line);
	if (!line)
		return (NULL);
	return (ft_extractline(&line));
}

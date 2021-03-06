/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:49:04 by rsanchez          #+#    #+#             */
/*   Updated: 2021/01/04 00:06:15 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	isnl(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int		extractline(char **buf, char **line, size_t nl, size_t len)
{
	if (len == 0)
	{
		if (*buf)
		{
			*line = *buf;
			*buf = NULL;
			return (0);
		}
		if (!(*line = malloc(sizeof(char))))
			return (-1);
		**line = '\0';
		return (0);
	}
	*line = substr_free(*buf, 0, nl, DONTFREE);
	*buf = substr_free(*buf, nl + 1, BUFFER_SIZE, DOFREE);
	if (!*line || !*buf)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*permbuf[10000];
	char		*tmpbuf;
	size_t		len;
	size_t		nl;

	if (fd < 0 || read(fd, 0, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(tmpbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	len = 1;
	while ((nl = isnl(permbuf[fd])) == 0 &&
			(len = read(fd, tmpbuf, BUFFER_SIZE)))
	{
		tmpbuf[len] = '\0';
		permbuf[fd] = join_free(permbuf[fd], tmpbuf, DOFREE, DONTFREE);
		if (!(permbuf[fd]))
		{
			free(tmpbuf);
			return (-1);
		}
	}
	free(tmpbuf);
	return (extractline(&(permbuf[fd]), line, nl - 1, len));
}

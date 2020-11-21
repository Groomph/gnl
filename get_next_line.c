/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 06:34:11 by romain            #+#    #+#             */
/*   Updated: 2020/11/21 18:30:24 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (!*buf)
		{
			*buf = malloc(sizeof(char));
			*buf[0] = '\0';
		}
		*line = *buf;
		*buf = NULL;
		return (0);
	}
	*line = my_substr_free(*buf, 0, nl, 0);
	*buf = my_substr_free(*buf, nl + 1, BUFFER_SIZE, 1);
	if (!*line || !*buf)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*permbuf[2000];
	char		tmpbuf[BUFFER_SIZE + 1];
	size_t		len;
	size_t		nl;

	if (fd < 0 || read(fd, tmpbuf, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	len = 1;
	while ((nl = isnl(permbuf[fd])) == 0 &&
			(len = read(fd, tmpbuf, BUFFER_SIZE)))
	{
		tmpbuf[len] = '\0';
		permbuf[fd] = my_strjoin_free(permbuf[fd], tmpbuf, 1, 0);
		if (!permbuf[fd])
			return (-1);
	}
	return (extractline(&permbuf[fd], line, nl - 1, len));
}

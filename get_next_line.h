/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:48:31 by rsanchez          #+#    #+#             */
/*   Updated: 2021/01/03 19:26:59 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define DOFREE 1
# define DONTFREE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		get_next_line(int fd, char **line);
char	*substr_free(char *str, size_t start, size_t len, int freestr);
char	*join_free(char *str1, char *str2, int freestr1, int freestr2);

#endif

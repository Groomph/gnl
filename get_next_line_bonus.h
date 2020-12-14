/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 07:16:41 by romain            #+#    #+#             */
/*   Updated: 2020/12/14 20:43:48 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
/*# include <limits.h>*/

# define DOFREE 1
# define DONTFREE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		get_next_line(int fd, char **line);
char	*substr_free(char *str, size_t start, size_t len, int freestr);
char	*join_free(char *str1, char *str2, int freestr1, int freestr2);

#endif

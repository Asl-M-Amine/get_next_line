/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:13:21 by marvin            #+#    #+#             */
/*   Updated: 2025/11/23 18:13:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_stash(char **stash)
{
	if (*stash)
		free(*stash);
	*stash = NULL;
	return (NULL);
}

char	*read_and_join(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	int		n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(stash, '\n') && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buf);
		free(tmp);
	}
	free(buf);
	return (stash);
}

char	*make_return(char **stash)
{
	char	*line;

	if (*stash && **stash)
	{
		line = file_line(*stash);
		*stash = clean_stash(*stash);
		return (line);
	}
	return (free_stash(stash));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_stash(&stash));
	stash = read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
		return (make_return(&stash));
	line = file_line(stash);
	stash = clean_stash(stash);
	return (line);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:45:39 by marvin            #+#    #+#             */
/*   Updated: 2025/11/27 21:45:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line_bonus.h"

static char	*read_into_stash(t_list *node)
{
	char	*buf;
	char	*tmp;
	int		n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(node->stash, '\n') && n > 0)
	{
		n = read(node->fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		tmp = node->stash;
		node->stash = ft_strjoin(node->stash, buf);
		free(tmp);
	}
	free(buf);
	return (node->stash);
}

char	*file_node(t_list *node, t_list **lst)
{
	char	*line;

	if (!read_into_stash(node))
	{
		ft_lstdel(lst, node);
		return (NULL);
	}
	line = file_line(node->stash);
	node->stash = clean_stash(node->stash);
	if (!node->stash)
		ft_lstdel(lst, node);
	return (line);
}

char	*get_next_line_bonus(int fd)
{
	static t_list	*lst;
	t_list			*node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = ft_lstchr(lst, fd);
	if (!node)
	{
		node = ft_lstnew(fd);
		ft_lstadd_back(&lst, node);
	}
	return (file_node(node, &lst));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:14:14 by marvin            #+#    #+#             */
/*   Updated: 2025/11/23 18:14:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int fd)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->stash = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*old_last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	old_last = ft_lstlast(*lst);
	old_last->next = new_node;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstchr(t_list *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lstdel(t_list **lst, t_list *target)
{
	t_list	*cur;

	if (!lst || !target)
		return ;
	if (*lst == target)
	{
		*lst = target->next;
		free(target->stash);
		free(target);
		return ;
	}
	cur = *lst;
	while (cur->next && cur->next != target)
		cur = cur->next;
	if (cur->next == target)
	{
		cur->next = target->next;
		free(target->stash);
		free(target);
	}
}

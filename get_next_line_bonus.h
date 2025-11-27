/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:13:48 by marvin            #+#    #+#             */
/*   Updated: 2025/11/23 18:13:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "get_next_line.h"

typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}	t_list;

char    *get_next_line_bonus(int fd);
t_list	*ft_lstnew(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstchr(t_list *lst, int fd);
void	ft_lstdel(t_list **lst, t_list *target);

#endif

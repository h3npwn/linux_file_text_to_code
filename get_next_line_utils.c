/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:25:48 by h3nix             #+#    #+#             */
/*   Updated: 2024/12/04 18:38:11 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->chunk = content;
	new_node->len = 0;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_laddback(t_list **list, t_list *node)
{
	t_list	*tmp;

	if (!node)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = ft_lstlast(*list);
	tmp->next = node;
}

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !*list || !list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		del((*list)->chunk);
		del(*list);
		*list = tmp;
	}
	*list = NULL;
}

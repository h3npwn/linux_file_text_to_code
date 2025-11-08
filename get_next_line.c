/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:32:25 by abahja            #+#    #+#             */
/*   Updated: 2024/12/04 18:40:33 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_nlen(t_list *list)
{
	int		i;
	t_list	*tmp;

	if (!list)
		return (0);
	i = 0;
	tmp = ft_lstlast(list);
	while (tmp->chunk[i])
	{
		if (tmp->chunk[i] == '\n')
		{
			i++;
			tmp->len = i;
			return (1);
		}
		i++;
	}
	tmp->len = i;
	return (0);
}

static void	fill_list(t_list **list, int fd)
{
	ssize_t		b_read;
	char		*c_read;
	t_list		*node;

	node = NULL;
	b_read = 0;
	while (!ft_nlen(*list))
	{
		c_read = NULL;
		node = NULL;
		node = ft_lstnew(c_read);
		node->chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		b_read = read(fd, node->chunk, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free (c_read);
			ft_lstclear(&node, free);
			return ;
		}
		node->chunk[b_read] = '\0';
		ft_laddback(list, node);
	}
}

static void	polish_list(t_list **list, int i, t_list *tmp, t_list *new)
{
	char	*chunk;

	if (!list || !*list)
		return ;
	tmp = ft_lstlast(*list);
	if (tmp->chunk[tmp->len] != '\0')
	{
		while (tmp->chunk[tmp->len + i] != '\0')
			i++;
		chunk = malloc(sizeof(char) * (i + 1));
		if (!chunk)
			return ;
		i = 0;
		while (tmp->chunk[tmp->len + i] != '\0')
		{
			chunk[i] = tmp->chunk[tmp->len + i];
			i++;
		}
		chunk[i] = '\0';
		new = ft_lstnew(chunk);
		ft_lstclear(list, free);
		*list = new;
	}
	else
		ft_lstclear(list, free);
}

static void	makestring(t_list *cache, char **line)
{
	int		ln_size;
	int		i;
	t_list	*temp;

	temp = cache;
	ln_size = 0;
	while (temp)
	{
		ln_size += temp->len;
		temp = temp->next;
	}
	if (!ln_size)
		return ;
	*line = malloc(sizeof(char) * (ln_size + 1));
	if (!*line)
		return ;
	ln_size = 0;
	while (cache && cache->chunk)
	{
		i = 0;
		while (i < cache->len && cache->chunk[i])
			(*line)[ln_size++] = cache->chunk[i++];
		cache = cache->next;
	}
	(*line)[ln_size] = '\0';
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	fill_list(&list, fd);
	if (!list)
		return (NULL);
	makestring(list, &line);
	polish_list(&list, 0, list, NULL);
	return (line);
}

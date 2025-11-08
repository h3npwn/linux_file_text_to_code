/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:45:53 by abahja            #+#    #+#             */
/*   Updated: 2025/01/31 10:46:21 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list{
	char			*chunk;
	size_t			a_size;
	int				len;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char *content);
void	ft_lstclear(t_list **list, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_laddback(t_list **list, t_list *node);
char	*get_next_line(int fd);
#endif
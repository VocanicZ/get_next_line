/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:18:37 by marvin            #+#    #+#             */
/*   Updated: 2022/11/04 22:18:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	static t_list	*last;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (0);
	lst_read(fd, &lst, &last);
	if (!lst)
		return (0);
	lst_pop(lst, &line);
	lst_pop2(&lst, &last);
	if (!line[0])
	{
		lst_free(lst);
		lst = 0;
		free(line);
		return (NULL);
	}
	return (line);
}

void	lst_read(int fd, t_list **lst, t_list **last)
{
	char	*buf;
	int		i;

	i = 1;
	while (!lst_contains(*last, '\n', 0) && i)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		i = read(fd, buf, BUFFER_SIZE);
		if ((!*last && !i) || i == -1)
		{
			free(buf);
			return ;
		}
		buf[i] = '\0';
		lst_append(lst, buf, i, last);
		free(buf);
	}
}

void	lst_append(t_list **lst, char *buf, int readed, t_list **last)
{
	int		i;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = 0;
	new_node->get = malloc(sizeof(char) * (readed + 1));
	if (!new_node->get)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->get[i] = buf[i];
		i++;
	}
	new_node->get[i] = '\0';
	if (!*lst)
	{
		*lst = new_node;
		*last = new_node;
		return ;
	}
	(*last)->next = new_node;
	(*last) = new_node;
}

void	lst_pop(t_list *lst, char **line)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	ft_realloc(line, lst);
	if (!*line)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->get[i])
		{
			if (lst->get[i] == '\n')
			{
				(*line)[j++] = lst->get[i];
				break ;
			}
			(*line)[j++] = lst->get[i++];
		}
		lst = lst->next;
	}
	(*line)[j] = '\0';
}

#include <stdio.h>

void	lst_pop2(t_list **lst, t_list **last)
{
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!lst || !clean_node)
		return ;
	clean_node->next = 0;
	i = lst_contains(*last, '\n', 1);
	printf("i -> %d\n", i);
	if ((*last)->get && (*last->get[i] == '\n'))
		i++;
	printf("new i -> %d\n", i);
	clean_node->get = malloc(sizeof(char) * ((ft_strlen((*last)->get) - i) + 1));
	if (!clean_node->get)
		return ;
	j = 0;
	while ((*last)->get[i])
		clean_node->get[j++] = (*last)->get[i++];
	clean_node->get[j] = '\0';
	lst_free(*lst);
	*lst = clean_node;
	*last = clean_node;
}
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

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static h_list	*list;
	h_list			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (0);
	tmp = lst_get(fd, &list);
	if (!list || !tmp)
		return (0);
	lst_read(fd, &tmp);
	if (!tmp->first)
		return (0);
	lst_pop(tmp->first, &line);
	lst_pop2(&tmp);
	if (!line[0])
	{
		lst_del(fd, &list);
		free(line);
		return (0);
	}
	return (line);
}

void	lst_read(int fd, h_list **list)
{
	char	*buf;
	int		i;

	i = 1;
	while (!lst_contains((*list)->last, '\n', 0) && i)
	{
		buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		i = read(fd, buf, BUFFER_SIZE);
		if ((!(*list)->last && !i) || i == -1)
		{
			free(buf);
			return ;
		}
		buf[i] = '\0';
		lst_append(list, buf, i);
		free(buf);
	}
}

void	lst_append(h_list **list, char *buf, int i)
{
	int		j;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = 0;
	new_node->get = (char *) malloc(sizeof(char) * (i + 1));
	if (!new_node->get)
		return ;
	j = 0;
	while (buf[j] && j < i)
	{
		new_node->get[j] = buf[j];
		j++;
	}
	new_node->get[j] = '\0';
	if (!(*list)->first)
		(*list)->first = new_node;
	else
		(*list)->last->next = new_node;
	(*list)->last = new_node;
}

void	lst_pop(t_list *lst, char **line)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	lst_malloc(line, lst);
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

void	lst_pop2(h_list **list)
{
	t_list	*new_node;
	t_list	*tmp;
	int		i;
	int		j;

	new_node = malloc(sizeof(t_list));
	if (!list || !new_node)
		return ;
	i = lst_contains((*list)->last, '\n', 1);
	if ((*list)->last->get && ((*list)->last->get[i] == '\n'))
		i++;
	new_node->get = (char *) malloc(sizeof(char) * ((ft_strlen((*list)->last->get) - i) + 1));
	if (!new_node->get)
		return ;
	j = 0;
	while ((*list)->last->get[i])
		new_node->get[j++] = (*list)->last->get[i++];
	new_node->get[j] = '\0';
	new_node->next = 0;
	tmp = (*list)->first;
	(*list)->first = new_node;
	(*list)->last = new_node;
	lst_free(tmp);
}
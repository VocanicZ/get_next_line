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

#include "get_next_line_tmp.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	//static t_list	*lst;
	//static t_list	*last;
	char			*line;
	static h_list	*list;

	printf("[0]");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (0);
	printf("[1]");
	lst_read(fd, &list);//&lst, &last);
	printf("[2]");
	if (!list->first)//lst)
	{
		printf("[2.1]");
		list = 0;
		return (0);
	}
	printf("[3]");
	lst_pop(list->first, &line);//lst, &line);
	printf("[4]");
	lst_pop2(&list);//&lst, &last);
	printf("[5]");
	if (!line[0])
	{
		printf("[5.1]");
		lst_free(list->first);//lst);
		printf("[5.2]");
		list = 0;//lst = 0;
		free(line);
		return (NULL);
	}
	printf("[6]");
	return (line);
}

void	lst_read(int fd, h_list **list)//t_list **lst, t_list **last)
{
	char	*buf;
	int		i;

	i = 1;
	while (!lst_contains((*list)->last, '\n', 0) && i)//last, '\n', 0) && i)
	{
		buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
		{
			*list = 0;
			return ;
		}
		i = read(fd, buf, BUFFER_SIZE);
		if ((!(*list)->last && !i) || i == -1)//last && !i) || i == -1)
		{
			free(buf);
			return ;
		}
		buf[i] = '\0';
		lst_append(list, buf, i);//lst, buf, i, last);
		free(buf);
	}
}

void	lst_append(h_list **list, char *buf, int i)//t_list **lst, char *buf, int readed, t_list **last)
{
	int		j;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		list = 0;
		return ;
	}
	new_node->next = 0;
	new_node->get = (char *) malloc(sizeof(char) * (i + 1));//readed + 1));
	if (!new_node->get)
	{
		free(new_node);
		list = 0;
		return ;
	}
	j = 0;
	while (buf[j] && j < i)
	{
		new_node->get[j] = buf[j];
		j++;
	}
	new_node->get[j] = '\0';
	if (!*list)//lst)
	{
		*list = malloc(sizeof(h_list));
		if (!*list)
			return ;
		(*list)->first = new_node;//*lst = new_node;
		(*list)->last = new_node;//*last = new_node;
		return ;
	}
	(*list)->last->next = new_node;//(*last)->next = new_node;
	(*list)->last = new_node;//(*last) = new_node;
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

void	lst_pop2(h_list **list)//t_list **lst, t_list **last)
{
	t_list	*new_node;
	int		i;
	int		j;

	new_node = malloc(sizeof(t_list));
	if (!list || !new_node)//lst || !new_node)
		return ;
	new_node->next = 0;
	i = lst_contains((*list)->last, '\n', 1);//last, '\n', 1);
	if ((*list)->last->get && ((*list)->last->get[i] == '\n'))//(*last)->get && ((*last)->get[i] == '\n'))
		i++;
	new_node->get = (char *) malloc(sizeof(char) * ((ft_strlen((*list)->last->get) - i) + 1));//last)->get) - i) + 1));
	if (!new_node->get)
		return ;
	j = 0;
	while ((*list)->last->get[i])//last)->get[i])
		new_node->get[j++] = (*list)->last->get[i++];//last)->get[i++];
	new_node->get[j] = '\0';
	lst_free((*list)->first);//lst);
	(*list)->first = new_node;//*lst = new_node;
	(*list)->last = new_node;//*last = new_node;
}
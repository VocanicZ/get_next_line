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
	struct z_list	*ptr;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (0);
	
	lst_read(fd, &ptr);
	if (!ptr)
		return (0);
	lst_pop(ptr, &line);
	lst_pop2(&ptr);
	if (!line[0])
	{
		lst_free(ptr);
		ptr = 0;
		free(line);
		return (NULL);
	}
	return (line);
}

void	lst_read(int fd, z_list **data)
{
	char	*buf;
	int		i;

	i = 1;
	while (!lst_contains((*data)->last, '\n', 0) && i)
	{
		buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		i = read(fd, buf, BUFFER_SIZE);
		if ((!(*data)->last && !i) || i == -1)
		{
			free(buf);
			return ;
		}
		buf[i] = '\0';
		lst_append(buf, i, data);
		free(buf);
	}
}

void	lst_append(char *buf, int readed, z_list **data)
{
	int		i;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = 0;
	new_node->get = (char *) malloc(sizeof(char) * (readed + 1));
	if (!new_node->get)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->get[i] = buf[i];
		i++;
	}
	new_node->get[i] = '\0';
	if (!*data)
	{
		*data = malloc(sizeof(z_list) * 2);
		if (!data)
			return ;
		(*data)->first = new_node;
		(*data)->last =new_node;
		return ;
	}
	(*data)->last->next = new_node;
	(*data)->last = new_node;
}

void	lst_pop(z_list *data, char **line)
{
	int	i;
	int	j;

	if (!data->first)
		return ;
	ft_realloc(line, data->first);
	if (!*line)
		return ;
	j = 0;
	while (data->first)
	{
		i = 0;
		while (data->first->get[i])
		{
			if (data->first->get[i] == '\n')
			{
				(*line)[j++] = data->first->get[i];
				break ;
			}
			(*line)[j++] = data->first->get[i++];
		}
		data->first = data->first->next;
	}
	(*line)[j] = '\0';
}

void	lst_pop2(z_list	**data)
{
	t_list	*new_node;
	int		i;
	int		j;

	new_node = malloc(sizeof(t_list));
	if (!data || !new_node)
		return ;
	new_node->next = 0;
	i = lst_contains((*data)->last, '\n', 1);
	if ((*data)->last->get && ((*data)->last->get[i] == '\n'))
		i++;
	new_node->get = (char *) malloc(sizeof(char) * ((ft_strlen((*data)->last->get) - i) + 1));
	if (!new_node->get)
		return ;
	j = 0;
	while ((*data)->last->get[i])
		new_node->get[j++] = (*data)->last->get[i++];
	new_node->get[j] = '\0';
	lst_free(*data);
	(*data)->first = new_node;
	(*data)->last = new_node;
}
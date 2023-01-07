/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
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
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (0);
	//line = NULL;
	// 1. read from fd and add to linked list
	lst_read(fd, &list);
	if (!list)
		return (0);
	// 2. extract from list to line
	extract_line(list, &line);
	// 3. clean up list
	lst_clean(&list);
	if (!line[0])
	{
		lst_free(list);
		list = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/* Uses read() to add characters to the list */

void	ft_read(int fd, t_list **list)
{
	char	*buf;
	int		readed;

	readed = 1;
	while (!lst_contains(*list, '\n') && readed)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*list == NULL && !readed) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		lst_append(list, buf, readed);
		free(buf);
	}
}

/* Adds the content of our buffer to the end of our list */

void	lst_append(t_list **list, char *buf, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = 0;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (!new_node->content)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	last = lst_last(*list);
	last->next = new_node;
}

/* Extracts all characters from our list and stores them in out line.
 * stopping after the first \n it encounters */

void	extract_line(t_list *list, char **line)
{
	int	i;
	int	j;

	if (!list)
		return ;
	generate_line(line, list);
	if (!*line)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*line)[j++] = list->content[i];
				break ;
			}
			(*line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}

/* After extracting the line that was read, we don't need those characters
 * anymore. This function clears the list so only the characters that have
 * not been returned at the end of get_next_line remain in our static list. */

void	lst_clean(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!list || !clean_node)
		return ;
	clean_node->next = 0;
	last = lst_last(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (!clean_node->content)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	lst_free(*list);
	*list = clean_node;
}
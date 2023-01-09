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
	static t_list	*lst;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (0);
	if (!lst)
	{
		lst = malloc(sizeof(t_list));
		if (!lst)
			return (NULL);
		lst->get = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!lst->get)
		{
			free(lst);
			lst = NULL;
			return (NULL);
		}
		i = read(fd, lst->get, BUFFER_SIZE);
		if (i <= 0)
		{
			free(lst->get);
			free(lst);
			lst = NULL;
			return (NULL);
		}
		lst->get[i] = '\0';
		lst->index = 0;
		lst->next = NULL;
	}
	lst_pop(lst, &line);
	if (!line[0])
	{
		free(lst->get);
		free(lst);
		lst = NULL;
		free(line);
		return (NULL);
	}
	return (line);
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
		i = lst->index;
		while (lst->get[i])
		{
			if (lst->get[i] == '\n')
			{
				(*line)[j++] = lst->get[i];
				break ;
			}
			(*line)[j++] = lst->get[i++];
		}
		if (lst->get[i] == '\n')
		{
			lst->index = i + 1;
			break ;
		}
		if (lst->get[i] == '\0')
		{
			if (read(fd, lst->get, BUFFER_SIZE) <= 0)
				break ;
			lst->index = 0;
		}
	}
	(*line)[j] = '\0';
}

void	ft_realloc(char **line, t_list *lst)
{
	int	i;
	int	len;
    char    *str;

	len = 0;
	while (lst)
	{
		i = 0;
        str = lst->get;
		while (str[i])
		{
			if (str[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		lst = lst->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}
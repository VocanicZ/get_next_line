/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasuphar <nasuphar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:17:41 by nasuphar          #+#    #+#             */
/*   Updated: 2023/01/26 23:36:07 by nasuphar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_get_next_line.h"

t_circular	*lst_get(int fd, t_circular **list)
{
	t_circular	*current;
	t_circular	*new_node;

	new_node = malloc(sizeof(t_circular));
	if (!new_node)
		return (0);
	new_node->fd = fd;
    new_node->first = 0;
    new_node->last = 0;
	if (!*list)
	{
		new_node->next = new_node;
		*list = new_node;
		return (new_node);
	}
	current = *list;
	if (current->fd > fd)
	{
		new_node->next = current;
		while (current->next != *list)
			current = current->next;
		current->next = new_node;
		*list = new_node;
		return (new_node);
	}
	while (current->next != *list && current->next->fd <= fd)
	{
		if (current->fd == fd)
        {
            free(new_node);
			return (current);
        }
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}

void	lst_del(int fd, t_circular **list)
{
	t_circular	*current;
	t_circular	*prev;

	current = *list;
	prev = current;
	if (!*list)
		return ;
	if (current->fd == fd)
	{
		if (current->next == *list)
		{
			*list = 0;
			free(current);
			return ;
		}
		while (current->next != *list)
			current = current->next;
		current->next = prev->next;
		*list = prev->next;
		free(prev);
		return ;
	}
	while (current->next != *list)
	{
		if (current->fd == fd)
		{
			prev->next = current->next;
			free(current);
			if (current == *list)
				*list = prev;
			return ;
		}
		prev = current;
		current = current->next;
	}
	if (current->fd == fd)
	{
		prev->next = *list;
		free(current);
	}
}

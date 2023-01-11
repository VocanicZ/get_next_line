/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus2.c.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:48:18 by marvin            #+#    #+#             */
/*   Updated: 2023/01/11 23:48:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

h_list *lst_get(int fd, h_list **list)
{
    h_list *current = *list;
    h_list *new_node = malloc(sizeof(h_list));

    new_node->fd = fd;
    new_node->first = 0;
    new_node->last = 0;
    if (!current || current->fd > fd)
    {
        new_node->next = current ? current : new_node;
        while (current->next != *list)
            current = current->next;
        if (current)
            current->next = new_node;
        *list = new_node;
    }
    else
    {
        while (current->next != *list && current->next->fd <= fd)
        {
            if (current->fd == fd)
            {
                free(new_node);
                return current;
            }
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return new_node;
}

void lst_del(int fd, h_list **list)
{
    h_list *current = *list;
    h_list *prev = current;

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
    while (current->next != *list) {
        if (current->fd == fd) {
            prev->next = current->next;
            free(current);
            if (current == *list) {
                *list = prev;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    if(current->fd == fd) {
        prev->next = *list;
		free(current);
    }
}
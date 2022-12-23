/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:24:54 by marvin            #+#    #+#             */
/*   Updated: 2022/12/23 16:24:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line3.h"

char    *reallocate_line_buffer(char *line, size_t size)
{
    char    *new_line;
    
    new_line = malloc(size);
    if (!new_line)
    {
        free(line);
        return (0);
    }
    strcpy(new_line, line);
    free(line);
    return (new_line);
}

char    *read_line(int fd, char *line, size_t size, int *i)
{
    ssize_t n;
    char    c;

    while ((n = read(fd, &c, 1)) > 0)
    {
        if (c == '\n')
        {
            line[*i] = '\0';
            return (line);
        }
        line[*i] = c;
        (*i)++;
        if (*i == size)
        {
            line = reallocate_line_buffer(line, size * 2);
            if (!line)
                return (0);
        }
    }
    return (line);
}

char *get_next_line(int fd)
{
    char *line;

    line = malloc(BUFFER_SIZE);
    if (!line)
        return (0);
    int i = 0;
    line = read_line(fd, line, BUFFER_SIZE, &i);
    if (!line)
        return (0);
    if (i > 0)
    {
        line[i] = '\0';
        return (line);
    }
    free(line);
    return (0);
}

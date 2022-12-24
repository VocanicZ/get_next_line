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

static char *reallocate_line_buffer(char *line, size_t size)
{
    char *new_line;

    new_line = malloc(size);
    if (new_line == NULL)
    {
        if (line != NULL)
            free(line);
        return (0);
    }
    ft_strncpy(new_line, line, size);
    if (line != NULL)
        free(line);
    return (new_line);
}

static char *read_line(int fd, char *line, size_t size, size_t *i, ssize_t *n, char *buffer)
{
    int j;

    while ((*n = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[*n] = '\0';
        j = -1;
        while (buffer[++j])
        {
            if (buffer[j] == '\n')
            {
                line[*i] = '\0';
                return (line);
            }
            line[(*i)++] = buffer[j];
            if (*i == size)
            {
                line = reallocate_line_buffer(line, size += BUFFER_SIZE);
                if (!line)
                    return (0);
            }
        }
    }
    return (line);
}

char *get_next_line(int fd)
{
    char *data[2];
    size_t i;
    ssize_t n;

    data[0] = malloc(BUFFER_SIZE);
    if (data[0] == NULL)
        return (NULL);
    data[1] = malloc(BUFFER_SIZE + 1);
    if (data[1] == NULL)
        return (NULL);
    i = 0;
    data[0] = read_line(fd, data[0], BUFFER_SIZE, &i, &n, data[1]);
    if (!data[0])
    {
        free(data[1]);
        return (NULL);
    }
    if (i > 0 || (i == 0 && n == 1))
    {
        data[0][i] = '\0';
        return (data[0]);
    }
    free(data[0]);
    free(data[1]);
    return (NULL);
}


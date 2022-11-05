/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:07:00 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 23:07:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *st_backup(char *to_save)
{
    static char *backup;

    if (!to_save)
        return (backup);
    else if (to_save == "")
        backup = "";
    else
        backup = to_save;
    return (0);
}

static char    *st_buffer(int fd, char *buffer)
{
    int size;

    if (!buffer)
        return (0);
    size = read(fd, buffer, BUFFER_SIZE);
    buffer[size] = 0;
    if (size <= 0)
    {
        free(buffer);
        return (0);
    }
    return (buffer);
}

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *backup;
    int  end;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
        return (0);
    if (!(backup = st_backup(0)))
    {
        if (!(buffer = st_buffer(fd, buffer)))
            return (0);
        backup = ft_strdup(buffer);
    }
    while (!(end = ft_strchr(backup, '\n')) && end != -1 && (buffer = st_buffer(fd, buffer)))
        backup = ft_strjoin(backup, buffer);
    free(buffer);
    if (end <= 0)
    {
        st_backup("");
        end++;
    }
    else
        st_backup(ft_strtrim(backup, end + 1, ft_strlen(backup)));
    backup = ft_strtrim(backup, 0, end + 1);
    return (backup);
}
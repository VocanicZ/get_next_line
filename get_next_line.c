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
#include <stdio.h>

static char    *st_backup(int fd, char *to_save)
{
    static char **backup;

    if (!backup)
        backup = malloc(sizeof(char *) * 100);
    if (!to_save)
    {
        if (!backup[fd])
            return (0);
        return (backup[fd]);
    }
    backup[fd] = to_save;
    return (0);
}

static char    *st_buffer(int fd, char *buffer)
{
    size_t  size;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    size = read(fd, buffer, BUFFER_SIZE);
    buffer[BUFFER_SIZE] = 0;
    if (size == -1)
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
    size_t  end;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (0);
    if (!(backup = st_backup(fd, 0)))
        backup = st_buffer(fd, buffer);
    else if (ft_strchr(backup, '\n' == 0))
        backup = ft_strjoin(backup, st_buffer(fd, buffer));
    printf("stored |%s|\n", backup);
    printf("\\n at %d\n", ft_strchr(backup, '\n'));
    end = ft_strchr(backup, '\n');
    if (end == 0)
        return (0);
    backup = ft_strtrim(backup, 0, end);
    st_backup(fd, backup);
    return (backup);
}
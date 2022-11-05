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

static char *st_backup(char *str)
{
    static char *backup;

    if (!backup)
        backup = "";
    if (str)
        backup = str;
    return (backup);
}

static char *st_buffer(int fd)
{
    char    *str;
    int     size;

    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!str)
        return (0);
    size = read(fd, str, BUFFER_SIZE);
    if (size <= 0)
    {
        free(str);
        if (size == 0)
            return ("");
        return (0);
    }
    str[size] = 0;
    return (str);
}

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *backup;
    int     end;

    backup = st_backup(0);
    end = ft_strchr(backup, '\n');
    while (end == -1)
    {
        buffer = st_buffer(fd);
        if (!buffer)
            return (0);
        if (buffer == "")
        {
            if (backup == "")
                return (0);
            break;
        }
        backup = ft_strjoin(&backup, &buffer);
        end = ft_strchr(backup, '\n');
    }
    if (end == -1)
    {
        st_backup("");
        return (backup);
    }
    buffer = ft_strpop(&backup, end);
    st_backup(backup);
    return (buffer);
}
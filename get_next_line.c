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

static char    *st_backup(int fd, char *to_save)
{
    //printf("(st_backup){\n");
    static char **backup;

    if (!backup)
    {
        backup = malloc(sizeof(char *) * 1000);
        if (!backup)
        {
            //printf("}\n");
            return (0);
        }
    }
    if (!to_save)
    {
        if (!backup[fd])
        {
            //printf("}\n");
            return (0);
        }
        //printf("__get backup[%d] -> %s}\n", fd, backup[fd]);
        return (backup[fd]);
    }
    backup[fd] = to_save;
    //printf("__set backup[%d] <- %s}\n", fd, to_save);
    return (0);
}

static char    *st_buffer(int fd, char *buffer)
{
    //printf("(st_buffer){\n");
    int  size;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
    {
        //printf("}\n");
        return (0);
    }
    size = read(fd, buffer, BUFFER_SIZE);
    //printf("__size = %d", size);
    if (size <= 0)
    {
        if (size == -1)
            free(buffer);
        //printf("}\n");
        return (0);
    }
    buffer[size] = 0;
    //printf("__buffer = %s}\n", buffer);
    return (buffer);
}

char    *get_next_line(int fd)
{
    //printf("(GET_NEXT_LINE){\n");
    char    *buffer;
    char    *backup;
    size_t  end;

    buffer = NULL;
    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
    {
        //printf("__catch error}\n");
        return (0);
    }
    if (!(backup = st_backup(fd, 0)))
    {
        if (!(buffer = st_buffer(fd, buffer)))
        {
            //printf("__buff error}\n");
            return (0);
        }
        backup = buffer;
    }
    while (!ft_strchr(backup, '\n') && (buffer = st_buffer(fd, buffer)))
    {
        //printf("__backup |%s|__buffer |%s|", backup, buffer);
        backup = ft_strjoin(backup, buffer);
    }
    //printf("__stored |%s|", backup);
    end = ft_strchr(backup, '\n');
    //printf("__\\n at %d", end);
    if (!end && buffer)
    {
        //printf("__end error}\n");
        return (0);
    }
    st_backup(fd, ft_strtrim(backup, end + 1, ft_strlen(backup)));
    backup = ft_strtrim(backup, 0, end + 1);
    free(buffer);
    //printf("__done}\n");
    return (backup);
}
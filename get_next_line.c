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

char    *st_backup(int fd, char *to_save)
{
    static char **backup;

    if (!backup)
        backup = malloc(sizeof(char *) * 4);
    if (!to_save)
        return (backup[fd]);
    backup[fd] = malloc(sizeof(char) * (ft_strlen(to_save) + 1));
    backup[fd] = to_save;
    return (0);
}

char    *get_next_line(int fd)
{
    char    *buffer;
    int     tmp;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (0);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    tmp = read(fd, buffer, BUFFER_SIZE);
    if (tmp == -1)
    {
        free(buffer);
        return (0);
    }
    else if (tmp )
}
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

char    *st_bufffer(int fd, char *to_save)
{
    static char **buffer;

    if (!to_save)
        return (buffer[fd]);
    buffer[fd] = to_save;
    return (0);
}
char    *get_next_line(int fd){
    return ("done");
}
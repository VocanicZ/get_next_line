/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasuphar <nasuphar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:52:04 by nasuphar          #+#    #+#             */
/*   Updated: 2023/01/27 02:44:29 by nasuphar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_get_next_line.h"
#include <stdio.h>

char    *get_next_line(int fd)
{
    static t_circular   *list;
    t_circular          *cur;
    char                *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (0);
    if (!(cur = lst_get(fd, &list)))
        return (0);
    printf("cur->fd = %d\n", cur->fd);
    lst_read(cur);
    printf("cur = [%s]\n", cur->first);
    return (line);
}

int     is_contain(char *str, char c, int returnIndex)
{
    int     i;

    if (!str)
        return (0);
    i = -1;
    while (str[++i])
    {
        if (str[i] == c)
        {
            if (returnIndex)
                return (i);
            return (1);
        }
    }
    if (returnIndex)
        return (i);
    return (0);
}

void    lst_read(t_circular *list)
{
    char    *buf;
    int     i;

    i = 1;
    printf("Buf");
    while (i && !is_contain(list->last, '\n', 0))
    {
        buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buf)
            return ;
        i = read(list->fd, buf, BUFFER_SIZE);
        if (i == -1)
        {
            free(buf);
            return ;
        }
        buf[i++] = '\0';
        printf("[%s]", buf);
        lst_append(list, buf, i);
        free(buf);
        printf("buf freee\n");
    }
    printf("\n");
}

char    *fd_pcat(char **dest, char *s1, char *s2)
{
    int i;
    int j;
    int k;

    i = -1;
    while (s1[++i])
        (*dest)[i] = s1[i]; 
    j = -1;
    k = i;
    while (s2[++j])
        (*dest)[i++] = s2[j];
    (*dest)[i] = '\0';
    printf("i = %d j = %d k = %d \n", i, j, k);
    return (&(*dest)[k]);
}

void    lst_append(t_circular *list, char *buf, int i)
{
    char    *newStr;

    newStr = malloc(sizeof(char) * (is_contain(list->first, '\0', 1) + i));
    if (!newStr)
        return ;
    if (!list->first)
    {
        list->first = fd_pcat(&newStr, 0, buf);
        return ;
    }
    printf("checkappend\n");
    list->last = fd_pcat(&newStr, list->first, buf);
    printf("b");
    free(list->first);
    printf("d\n");
    list->first = newStr;
}
/* can you check for memory leak from this unfinished get_next_line funtion i got segmentation fault, in my openion i think its caused by line 107 */
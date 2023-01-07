/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:40:00 by marvin            #+#    #+#             */
/*   Updated: 2022/11/05 20:40:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    printf("ft_strlen(%s)\n", s);

    size_t  i;
    
    i = 0;
    while (*s++)
        i++;
    printf("ft_strlen: return(%ld)\n", i);
    return (i);
}

int ft_strchr(const char *s, int c)
{
    printf("ft_strchr(%s, %c)\n", s, c);
    int i;

    i = 0;
    while (*s && *s != c)
    {
        s++;
        i++;
    }
    if (*s-- != c)
    {
        printf("ft_strchr: return(-1)\n");
        return (-1);
    }
    printf("ft_strchr: return(%d)\n", i);
    return (i);
}

char    *ft_strjoin(char **s1, char **s2)
{
    printf("ft_strjoin(%s, %s)\n", *s1, *s2);
    char    *str;
    size_t  i;
    size_t  j;

    str = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
    if (!str)
        return (0);
    i = 0;
    j = 0;
    while ((*s1)[j])
        str[i++] = (*s1)[j++];
    free(*s1);
    j = 0;
    while ((*s2)[j])
        str[i++] = (*s2)[j++];
    free(*s2);
    str[i] = 0;
    printf("ft_strjoin: return(%s)\n", str);
    return (str);
}
/*
char    *ft_strpop(char **s, int end)
{
    printf("ft_strpop(%s, %d)\n", *s, end);
    int i;
    int j;
    char    *pop;
    char    *buffer;

    pop = malloc(sizeof(char) * (end + 1));
    if (!pop)
        return (0);
    i = 0;
    while ((*s)[i] && i < end)
    {
        printf("ft_strpop(%c && %d < %d)\n", (*s)[i], i, end);
        pop[i] = (*s)[i++];
    }
    pop[i] = 0;
    printf("ft_strpop(pop = %s, i = %d)\n", pop, i);
    i = ft_strlen(*s) - end - 1;
    if (!i)
    {
        free(*s);
        *s = "";
    }
    buffer = malloc(sizeof(char) * (i + 1));
    if (!buffer)
        return (0);
    j = 0;
    while (j < i)
        buffer[j++] = (*s)[++end + i];
    buffer[j] = 0;
    free(*s);
    *s = buffer;
    printf("ft_strpop: return(%s, %s)\n", pop, *s);
    return (pop);
}*/
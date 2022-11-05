/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:33:19 by marvin            #+#    #+#             */
/*   Updated: 2022/10/31 18:33:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int  ft_strchr(const char *s, int c)
{
    size_t  len;
    int  i;

    len = ft_strlen(s);
    i = 0;
    while (i < len)
    {
        if (s[i] == c)
        {
            if (i == 0)
                return (-1);
            return (i);
        }
        i++;
    }
    return (0);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *ptr;
    size_t  i;
    
    if (!s1 || !s2)
        return (0);
    ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!ptr)
        return (0);
    i = 0;
    while (*s1)
        ptr[i++] = *s1++;
    while (*s2)
        ptr[i++] = *s2++;
    ptr[i] = '\0';
    return (ptr);
}

char    *ft_strtrim(char *s, size_t start, size_t stop)
{
    char    *str;
    size_t  i;
    
    if (start == stop)
        return (0);
    str = malloc(sizeof(char) * (stop - start));
    i = 0;
    while (start < stop)
        str[i++] = s[start++];
    str[i] = 0;
    free(s);
    return (str);
}

char    *ft_strdup(char *s)
{
    size_t  len;
    size_t  i;
    char    *str;

    len = ft_strlen(s);
    str = malloc(sizeof(char) * (len + 1));
    i = 0;
    while (s[i])
        str[i] = s[i++];
    str[i] = 0;
    return (str);
}
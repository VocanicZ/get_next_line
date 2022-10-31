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
    //printf("strlening..\n");
    size_t  i;

    i = 0;
    while (*s++)
        i++;
    //printf("returning %d\n", i);
    return (i);
}

size_t  ft_strchr(const char *s, int c)
{
    //printf("strchring..\n");
    size_t  len;
    size_t  i;

    len = ft_strlen(s);
    i = 0;
    while (i < len)
    {
        if (s[i] == c){
            //printf("returning %d\n", i);
            return (i);
        }
        i++;
    }
    //printf("returning 0\n");
    return (0);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    //printf("strjoining..\n");
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
    //printf("returning %s\n", ptr);
    return (ptr);
}

char    *ft_strtrim(char const *s, size_t start, size_t stop)
{
    //printf("strtrimming..\n");
    char    *str;
    size_t  i;
    
    str = malloc(sizeof(char) * (stop - start));
    i = 0;
    while (start < stop)
        str[i++] = s[start++];
    str[i] = 0;
    //printf("returning %s\n", str);
    return (str);
}
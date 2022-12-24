#include "get_next_line3.h"

char    *ft_strcpy(char *dest, const char *src)
{
    char *d;
    const char *s;

    d = dest;
    s = src;
    while (*s)
        *d++ = *s++;
    *d = '\0';

    return dest;
}
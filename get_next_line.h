#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
size_t  ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strtrim(char const *s, size_t start, size_t stop);
#endif
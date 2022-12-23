#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
#  endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char    *get_next_line(int fd);
char    *reallocate_line_buffer(char *line, size_t size);
char    *read_line(int fd, char *line, size_t size, int *i);

# endif
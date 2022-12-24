#include "get_next_line4.h"

# define BUFFER_SIZE =1
static char    *reallocate_line_buffer(char *line, size_t size)
{
    char    *new_line;

    new_line = malloc(size);
    if (new_line == NULL)
    {
        free(line);
        return (0);
    }
    ft_strcpy(new_line, line);
    free(line);
    return (new_line);
}

static char    *read_line(int fd, char *line, size_t size, int *i, ssize_t *n, char *buffer)
{
    int     j;

    while ((*n = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[*n] = '\0';
        j = -1;
        while (buffer[++j])
        {
            if (buffer[j] == '\n')
            {
                line[*i] = '\0';
                return (line);
            }
            line[(*i)++] = buffer[j];
            if (*i == size)
            {
                line = reallocate_line_buffer(line, size += BUFFER_SIZE);
                if (!line)
                    return (0);
            }
        }
    }
    free(buffer);
    return (line);
}

char *get_next_line(int fd)
{
    char        *line;
    char        *buffer;
    int         i;
    ssize_t     n;

    line = malloc(BUFFER_SIZE);
    if (line == NULL)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
        return (NULL);
    i = 0;
    line = read_line(fd, line, BUFFER_SIZE, &i, &n, buffer);
    if (!line)
    {
        free(buffer);
        return (NULL);
    }
    if (i > 0 || (i == 0 && n == 1))
    {
        line[i] = '\0';
        return (line);
    }
    free(line);
    free(buffer);
    return (NULL);
}
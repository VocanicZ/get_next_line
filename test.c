#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int fd;
    char *line;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: test file\n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    if (close(fd) < 0)
    {
        perror("close");
        return 1;
    }

    return 0;
}

#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc >= 2)
    {
        argv++;
        while (*argv)
        {
            printf("------------------------------\n");
            printf("path = %s\n", *argv);
            fd = open(*argv, O_RDONLY);
            printf("fd = %d\n", fd);
            while (line = get_next_line(fd))
                printf("line -> |%s|\n", line);
            argv++;
        }
    }
    return (0);
}
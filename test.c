#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char *str;

    if (argc >= 2)
    {
        argv++;
        while (*argv)
        {
            printf("------------------------------\n");
            printf("path = %s\n", *argv);
            fd = open(*argv, O_RDONLY);
            printf("fd = %d\n", fd);
            printf("line->|%s|\n", get_next_line(fd));
            printf("line2->|%s|\n", get_next_line(fd));
            argv++;
        }
    }
    return (0);
}
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *str;

    if (argc >= 2)
    {
        while (*argv)
        {
            printf("path = %s\n", *argv);
            fd = open(*argv, O_RDONLY);
            printf("fd = %d\n", fd);
            st_buffer(fd, *argv);
            printf("%s\n", st_buffer(fd, 0));
        }
    }
}
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *str;

    if (argc >= 2)
    {
        argv++;
        while (*argv)
        {
            printf("path = %s\n", *argv);
            fd = open(*argv, O_RDONLY);
            printf("fd = %d\n", fd);
            if (fd != -1)
            {
                st_backup(fd, *argv);
                printf("test->%s\n", st_backup(fd, 0));
            }
            argv++;
        }
    }
    return (0);
}
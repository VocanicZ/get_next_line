#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int randint = 1 + rand() / (RAND_MAX / (4 - 1 + 1) + 1);

    if (argc == 5)
    {
        while (argc--)
        {
            printf("------------------------------\n");
            printf("path = %s\n", *argv);
            fd = open(argv[randint], O_RDONLY);
            printf("fd = %d\n", fd);
            printf("line -> |%s|\n", get_next_line(fd));
        }
    }
    return (0);
}
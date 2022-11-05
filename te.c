#include <stdio.h>
#include <stdlib.h>

void    ft_free(char **s)
{
    free(*s);
    *s = "Hi";
}

void    ft_print(char **s)
{
    for (int i = 0; i < 10; i++)
        printf("%c\n", (*s)[i]);
}

int main(void)
{
    char *a;

    a = malloc(sizeof(char) * 6);
    printf("a = %s\n", a);
    a = "Hello";
    ft_print(&a);
    printf("a = %s\n", a);
    ft_free(&a);
    printf("a = %s\n", a);
}
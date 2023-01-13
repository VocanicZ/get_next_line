#include "circular.h"

h_list *lst_get(int fd, h_list **list)
{
    h_list *current;
    h_list *new_node;
    
    new_node = malloc(sizeof(h_list));
    new_node->fd = fd;
    new_node->next = new_node;
    current = *list;

    if (!current)
    {
        *list = new_node;
        return new_node;
    }
    while (current->next != *list)
    {
        if (current->fd == fd)
            return current;
        current = current->next;
    }
    if (current->fd <= fd) {
        new_node->next = current->next;
        current->next = new_node;
    } else {
        current->next = new_node;
        new_node->next = *list;
        *list = new_node;
    }
    /*
    if (current->fd > fd)
    {
        new_node->next = current;
        while (current->next != *list)
            current = current->next;
        current->next = new_node;
        *list = new_node;
        return new_node;
    }
    while (current->next != *list && current->next->fd <= fd) {
        if (current->fd == fd) {
            return current;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;*/
    return new_node;
}

void lst_del(int fd, h_list **list)
{
    h_list *current = *list;
    h_list *prev = current;

    if (!*list)
        return ;
    if (current->fd == fd)
    {
        if (current->next == *list)
        {
            *list = 0;
            free(current);
            return ;
        }
        while (current->next != *list)
            current = current->next;
        current->next = prev->next;
        *list = prev->next;
        free(prev);
        return ;
    }
    while (current->next != *list) {
        if (current->fd == fd) {
            prev->next = current->next;
            free(current);
            if (current == *list) {
                *list = prev;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    if(current->fd == fd) {
        prev->next = *list;
		free(current);
    }
}

void lst_print(h_list *list)
{
    h_list *current;

    if (!list) {
        printf("The list is empty\n");
        return;
    }
    current = list;
    printf("Circular buffer list: ");
    while (current->next != list) 
    {
        printf("[%d], ", current->fd);
        current = current->next;
    }
    printf("[%d] -> [%d]\n", current->fd, current->next->fd);
}

void    main(void)
{
    static h_list  *list;
    int     ran;
    int     i;

    printf("generateing circular\n");
    srand(time(NULL));
    i = 0;
    do
    {
        ran = rand() % 100;
        printf("round %d : rand gen-> %d\n", i, ran);
        printf("get -> %d\n", lst_get(ran, &list)->fd);
        lst_print(list);
        i++;
    } while (i < 10);
    while (1)
    {
        printf("enter node to delete:");
        scanf("%d", &ran);
        printf("del -> %d\n", ran);
        lst_del(ran, &list);
        printf("DONE VVV\n");
        lst_print(list);
    }
}
#include "circular.h"

h_list *lst_get(int fd, h_list **list)
{
    h_list *current;

    // If the list is empty, create a new node and set it to point to itself
    if (!*list) {
        h_list *new_node = malloc(sizeof(h_list));
        new_node->fd = fd;
        new_node->next = new_node;
        *list = new_node;
        return new_node;
    }
    current = *list;
    h_list *new_node = malloc(sizeof(h_list));
    new_node->fd = fd;
    if (current->fd > fd)
    {
        new_node->next = current;
        while (current->next != *list)
            current = current->next;
        current->next = new_node;
        *list = new_node;
        return new_node;
    }
    // Iterate through the circular buffer
    while (current->next != *list && current->next->fd <= fd) {
        if (current->fd == fd) {
            // Node with matching fd found, return it
            return current;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return new_node;
}

void lst_del(int fd, h_list **list)
{
    h_list *current = *list;
    h_list *prev = current;

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
    // if current is the last node and fd is equal to fd
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
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
    
    // Iterate through the circular buffer
    while (current->next != *list && current->fd <= fd) {
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

    // If the list is empty, there's nothing to print
    if (!list) {
        printf("The list is empty\n");
        return;
    }
    current = list;
    printf("Circular buffer list: ");
    do {
        printf("[%d] ", current->fd);
        current = current->next;
    } while (current != list);
    printf("\n");
}

void    main(void)
{
    static h_list  *list;
    int     ran;
    int     i;

    printf("start\n");
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
}
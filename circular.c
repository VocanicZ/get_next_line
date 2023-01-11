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
    
    // Iterate through the circular buffer
    while (current->next != *list) {
        if (current->fd == fd) {
            // Node with matching fd found, return it
            return current;
        }
        current = current->next;
    }

    // If no matching node was found, create a new one
    h_list *new_node = malloc(sizeof(h_list));
    new_node->fd = fd;
    new_node->next = current->next;
    current->next = new_node;

    // Insert the new node in front of the node with fd < input fd
    h_list *node = *list;
    while (node->next != *list && node->next->fd < fd) {
        node = node->next;
    }
    new_node->next = node->next;
    node->next = new_node;
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
        printf("[%d]{%d} ", current->fd, list->fd);
        current = current->next;
    } while (current != list);
    printf("\n");
}

void    main(void)
{
    static h_list  *list;
    int     ran;

    printf("start\n");
    ran = 0;
    while (ran < 10)
    {
        lst_get(ran, &list);
        lst_print(list);
        ran++;
    }
}
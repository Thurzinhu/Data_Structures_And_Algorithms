#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/dynamic_operations.h"

linked_list *build_linked_list()
{
    linked_list *new = malloc(sizeof(linked_list));
    new->head = NULL;
    new->tail = NULL;
    new->length = 0;
    
    return new;
}

void delete_list(linked_list *list)
{
    while (list->head != NULL)
        remove_first(list);

    free(list);
}
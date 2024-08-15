#include <stdio.h>
#include <stdlib.h>
#include "../include/static_operations.h"

node *get_at(linked_list *list, int idx)
{
    if (idx < 0 || idx >= list->length)
        return NULL;

    node *tmp = list->head;
    for (int i = 0; i < idx; i++)
        tmp = tmp->next;

    return tmp;
}

void set_at(linked_list *list, int idx, int val)
{
    node *tmp = get_at(list, idx);
    if (tmp == NULL)
        return;

    tmp->data = val;
}

void print_list(linked_list *list)
{
    node *tmp = list->head;

    while (tmp != NULL)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }

    printf("NULL\n");
}

int find(linked_list *list, int val)
{
    return helper_find(list->head, val);
}

int helper_find(node *cur, int val)
{
    if (cur == NULL)
        return 0;

    return cur->data == val ? 1 : helper_find(cur->next, val);
}

void reverse_list(linked_list *list)
{
    helper_reverse_list(list->head);
    
    node *aux = list->head;
    list->head = list->tail;
    list->tail = aux; 
}

void helper_reverse_list(node *cur)
{
    if (cur == NULL || cur->next == NULL)
        return;

    helper_reverse_list(cur->next);
    cur->next->next = cur;
    cur->next = NULL;
}
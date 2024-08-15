#include <stdio.h>
#include <stdlib.h>
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"

void insert_first(linked_list *list, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = list->head;
    
    list->head = new;
    
    if (list->length == 0)
        list->tail = new;

    list->length++;
}

void insert_last(linked_list *list, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (list->length == 0)
        list->head = new;
    else
        list->tail->next = new;

    list->tail = new;

    list->length++;
}

void remove_first(linked_list *list)
{
    if (!list->length)
        return;
    
    if (list->length == 1)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        node *tmp = list->head;
        list->head = list->head->next;

        free(tmp);
    }

    list->length--;
}

void remove_last(linked_list *list)
{
    if (!list->length)
        return;

    if (list->length == 1)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        node *new_tail = get_at(list, list->length - 2);
        free(new_tail->next);

        list->tail = new_tail;
        new_tail->next = NULL;
    }

    list->length--;
}

/*
    This function receives a list pointer and a function pointer whose signature is as follows:
    bool (*function)(int)
    
    This function is applied to every node in the linked list and it determines wether the current
    node should be removed or not

    As an example, two functions where declared below: one to test if a number is even and the other
    to test if a number is odd. When the first one is passed as an argument, all even numbers are removed. 
    Whereas, when the second one is passed as an argument all odd numbers are removed.

*/
void remove_nodes_matching_condition(linked_list *list, remove_function function)
{
    if (!list->length)
        return;

    node *prev = list->head;
    node *cur = list->head->next;
    while (cur != NULL)
    {
        if (function(cur->data))
        {
            node *tmp = cur;
            cur = cur->next;
            prev->next = cur;

            free(tmp);
            list->length--;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    list->tail = get_at(list, list->length - 1);

    if (function(list->head->data))
        remove_first(list);
}

bool is_even(int n)
{
    return n % 2 == 0;
}

bool is_odd(int n)
{
    return n % 2 == 1;
}
#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"

LinkedList *buildLinkedList()
{
    LinkedList *newList = malloc(sizeof(LinkedList));
    if (newList == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    newList->head = NULL;
    newList->size = 0;

    return newList;
}

void deleteLinkedList(LinkedList *list)
{
    Node *tmp = list->head;
    while(tmp != NULL)
    {
        Node *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    free(list);
}

void displayList(LinkedList *list)
{
    for (Node *tmp = list->head; tmp != NULL; tmp = tmp->next)
    {
        displayBook(tmp->info);
    }
}

void displayBook(Book b)
{
    printf("\n\n----------------------------------\n");
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Year: %i\n", b.year);
    printf("Quantity: %i\n", b.quantity);
    printf("----------------------------------\n\n");
}
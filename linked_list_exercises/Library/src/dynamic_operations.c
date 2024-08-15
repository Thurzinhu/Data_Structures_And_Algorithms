#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dynamic_operations.h"

void insere_livro(LinkedList *list, char *title, char *author, int year, int quantity)
{
    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->info.title, title);
    strcpy(newNode->info.author, author);
    newNode->info.year = year;
    newNode->info.quantity = quantity;

    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}
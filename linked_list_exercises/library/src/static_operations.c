#include <stdio.h>
#include <stdlib.h>
#include "../include/static_operations.h"

int quantidade_livros(LinkedList *list)
{
    Node*tmp = list->head;
    int totalBooks = 0;
    while(tmp != NULL)
    {
        totalBooks += tmp->info.quantity;
        tmp = tmp->next;
    }

    return totalBooks;
}

void livros_ano(LinkedList *list, int year)
{
    Node*tmp = list->head;
    while(tmp != NULL)
    {
        if (tmp->info.year == year)
        {
            displayBook(tmp->info);
        }

        tmp = tmp->next;
    }
}

void livros_ano_rec(LinkedList *list, int year)
{
    return helper_livros_ano_rec(list->head, year);
}

void helper_livros_ano_rec(Node *current, int year)
{
    if (current == NULL)
    {
        return;
    }

    if (current->info.year == year)
    {
        displayBook(current->info);
    }

    helper_livros_ano_rec(current->next, year);
}

void separa_ano(LinkedList *list, int year)
{
    Node *prev = NULL;
    Node *cur = list->head;

    while(cur != NULL)
    {
        if (cur->info.year != year)
        {
            Node *tmp = cur;
            if (prev != NULL)
            {
                prev->next = cur->next;
            }   
            else
            {
                list->head = cur->next;
            }

            cur = cur->next;
            free(tmp);

            list->size--;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
}
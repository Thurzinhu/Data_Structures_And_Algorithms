#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/static_operations.h"

void printPhoneBook(LinkedList *phoneBook)
{
    if (phoneBook->size == 0)
    {
        printf("\n\n######### No Contacts :( #########\n");
    }

    for (Node *tmp = phoneBook->head; tmp != NULL; tmp = tmp->next)
    {
        displayContact(tmp->info);
    }
}

Node *findContact(LinkedList *phoneBook, char *targetContact)
{
    for (Node *tmp = phoneBook->head; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(tmp->info.name, targetContact) == 0)
        {
            return tmp;
        }
    }

    return NULL;
}

void updateContact(LinkedList *phoneBook, char *targetContact)
{
    Node *tmp = findContact(phoneBook, targetContact);
    if (tmp != NULL)
    {
        getContactInfo(&tmp->info, "Updating Contact!");
    }
    else
    {
        printf("Could not find this contact :(\n");
    }
}
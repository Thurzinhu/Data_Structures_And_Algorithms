#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"

void insertContact(LinkedList *phoneBook, Contact *newContact)
{
    Node *newNode = malloc(sizeof(Node));

    if (newContact == NULL)
    {
        getContactInfo(&newNode->info, "Insert Contact information:");
    }
    else
    {
        strcpy(newNode->info.name, newContact->name);
        strcpy(newNode->info.phone, newContact->phone);
        strcpy(newNode->info.cellPhone, newContact->cellPhone);
        strcpy(newNode->info.email, newContact->email);
        newNode->info.birthday.day = newContact->birthday.day;
        newNode->info.birthday.month = newContact->birthday.month;
    }
    
    Node *prev = NULL;
    Node *cur = phoneBook->head;

    while(cur != NULL)
    {
        if (strcmp(newNode->info.name, cur->info.name) <= 0)
            break;

        prev = cur;
        cur = cur->next;
    }

    newNode->next = cur;

    // inserting at the middle or end
    if (prev != NULL)
    {
        prev->next = newNode;
    }
    // inserting at the beggining
    else
    {
        phoneBook->head = newNode;
    }

    phoneBook->size++;
}

void removeContact(LinkedList *phoneBook, char *targetContact)
{
    Node *prev = NULL;
    Node *cur = phoneBook->head;
    while (cur != NULL)
    {
        if (isEqualContact(cur->info.name, targetContact))
        {
            break;
        }

        prev = cur;
        cur = cur->next;
    }
    
    if (cur != NULL)
    {
        if (prev != NULL)
        {
            prev->next = cur->next;
        }
        else
        {
            phoneBook->head = cur->next;
        }

        free(cur);
        
        phoneBook->size--;
    }
    else
    {
        printf("Could not find contact :(\n");
    }
}

void removeDuplicates(LinkedList *phoneBook)
{
    for (Node *tmp = phoneBook->head; tmp != NULL; tmp = tmp->next)
    {
        phoneBook->size -= removeNodesMatchingName(tmp, tmp->info.name);
    }
}

int removeNodesMatchingName(Node *start, char *targetName)
{
    Node *prev = start;
    Node *cur = start->next;
    int countRemovedNodes = 0;
    while (cur != NULL)
    {
        if (isEqualContact(targetName, cur->info.name))
        {
            Node *tmp = cur;
            cur = cur->next;
            prev->next = cur;

            free(tmp);

            countRemovedNodes++;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    return countRemovedNodes;
}

int isEqualContact(char *name1, char *name2)
{
    return (strcmp(name1, name2) == 0);
}
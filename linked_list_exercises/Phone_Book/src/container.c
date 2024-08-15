#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"

LinkedList *buildPhoneBook()
{
    LinkedList *newPhoneBook = malloc(sizeof(LinkedList));
    if (newPhoneBook == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newPhoneBook->head = NULL;
    newPhoneBook->size = 0;

    return newPhoneBook;
}

void deletePhoneBook(LinkedList *phoneBook)
{
    Node *tmp = phoneBook->head;
    while (tmp != NULL)
    {
        Node *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    free(phoneBook);
}

void getContactInfo(Contact *c, char *mode)
{
    printf("\n%s\n\n", mode);

    printf("Enter new name (max 40 characters): ");
    scanf(" %[^\n]s", c->name);

    printf("Enter new phone number (max 15 characters): ");
    scanf(" %[^\n]s", c->phone);

    printf("Enter new cell phone number (max 15 characters): ");
    scanf(" %[^\n]s", c->cellPhone);

    printf("Enter new email (max 40 characters): ");
    scanf(" %[^\n]s", c->email);

    printf("Enter new birthday (format: day month): ");
    scanf("%i %i", &c->birthday.day, &c->birthday.month);
}

void displayContact(Contact c)
{
    printf("\n\n----------------------------------\n");
    printf("Name: %s\n", c.name);
    printf("Phone: %s\n", c.phone);
    printf("Cell Phone: %s\n", c.cellPhone);
    printf("Email: %s\n", c.email);
    printf("Birthday: %d/%d\n", c.birthday.day, c.birthday.month);
    printf("----------------------------------\n\n");
}

void phoneBookInterface(LinkedList *phoneBook) 
{
    if (phoneBook == NULL)
    {
        phoneBook = buildPhoneBook();
    }
    char name[41];
    int choice;

    do 
    {
        printf("\n---------------Menu---------------\n");
        printf("1. Insert Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Remove Contact\n");
        printf("6. Remove Duplicate Contacts\n");
        printf("7. Exit\n");

        printf("Choose an operation: ");
        scanf("%i", &choice);

        printf("\n----------------------------------\n\n");
        switch(choice) 
        {
            case 1:
                printf("Insert Contact selected.\n");
                insertContact(phoneBook, NULL);
                break;
            case 2:
                printf("List Contacts selected.\n");
                printPhoneBook(phoneBook);
                break;
            case 3:
                printf("Search Contact selected.\n");
                printf("Type the name to search for: ");
                scanf(" %[^\n]s", name);
                Node *tmp = findContact(phoneBook, name);

                if (tmp != NULL)
                    displayContact(tmp->info);
                else
                    printf("Could not find Contact :(\n");
                break;
            case 4:
                printf("Edit Contact selected.\n");
                printf("Type the name of the contact you want to update: ");
                scanf(" %[^\n]s", name);
                updateContact(phoneBook, name);
                break;
            case 5:
                printf("Remove Contact selected.\n");
                printf("Type the name of the contact you want to remove: ");
                scanf(" %[^\n]s", name);
                removeContact(phoneBook, name);
                break;
            case 6:
                printf("Remove Duplicate Contacts selected.\n");
                removeDuplicates(phoneBook);
                break;
            case 7:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
        printf("\n\n");
    } 
    while(choice != 7);

    deletePhoneBook(phoneBook);
}

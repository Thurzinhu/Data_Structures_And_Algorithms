#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct 
{
    int day;
    int month;
}
Date;

typedef struct
{
    char name[41];
    char phone[16];
    char cellPhone[16];
    char email[41];
    Date birthday;
}
Contact;

typedef struct Node
{
    Contact info;
    struct Node *next;
}
Node;

typedef struct
{
    Node *head;
    int size;
}
LinkedList;

LinkedList *buildPhoneBook();
void deletePhoneBook(LinkedList *phoneBook);
void getContactInfo(Contact *c, char *mode);
void displayContact(Contact c);
void phoneBookInterface(LinkedList *phoneBook);

#endif
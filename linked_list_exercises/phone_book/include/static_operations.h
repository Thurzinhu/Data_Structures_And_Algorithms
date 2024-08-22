#ifndef STATIC_OPERATIONS_H
#define STATIC_OPERATIONS_H

#include "container.h"

void printPhoneBook(LinkedList *phoneBook);
Node *findContact(LinkedList *phoneBook, char *targetContact);
void updateContact(LinkedList *phoneBook, char *targetContact);

#endif
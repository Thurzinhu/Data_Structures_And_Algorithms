#ifndef DYNAMIC_OPERATIONS_H
#define DYNAMIC_OPERATIONS_H

#include "container.h"

void insertContact(LinkedList *phoneBook, Contact *newContact);
void removeContact(LinkedList *phoneBook, char *targetContact);
void removeDuplicates(LinkedList *phoneBook);
int removeNodesMatchingName(Node *start, char *targetName);
int isEqualContact(char *name1, char *name2);

#endif
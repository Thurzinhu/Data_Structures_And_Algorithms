#ifndef STATIC_OPERATIONS_H
#define STATIC_OPERATIONS_H

#include "container.h"

int quantidade_livros(LinkedList *list);
void livros_ano(LinkedList *list, int year);
void livros_ano_rec(LinkedList *list, int year);
void helper_livros_ano_rec(Node *current, int year);
void separa_ano(LinkedList *list, int year);

#endif
#ifndef DYNAMIC_OPERATIONS_H
#define DYNAMIC_OPERATIONS_H

#include "./container.h"
#include <stdbool.h>

char pop(stack *s);
void push(stack *s, char item);
bool isBalanced(char *string);

#endif

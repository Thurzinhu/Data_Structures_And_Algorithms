#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#define MAX_VALUE 1000000

void compare_sort_algorithms();
void terminate(const char *message);
void print_array(int *array, int length);
void is_sorted(int *array, int length);
void copy_elements(int *source, int *destination, int start, int end);
int *generate_array(int length, int max);

#endif
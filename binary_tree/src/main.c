#include <stdio.h>
#include <stdlib.h>
#include "../include/dynamic_operations.h"
#include "../include/static_operations.h"
#include "../include/set_interface.h"

int main()
{
    binaryTree *tree = create_binary_tree();
    for (int i = 'Z'; i >= 'A'; i--)
        insert_node(tree, (char)i);
    
    subtree_iter(tree->root);
    printf("\n");

    char key = 'Z';
    node *next = subtree_find_next(tree->root, key);
    node *prev = subtree_find_previous(tree->root, key);

    if (next != NULL)
        printf("Node after %c: %c\n", key, next->item);
    if (prev != NULL)
        printf("Node before %c: %c\n", key, prev->item);

    printf("Size: %i\n", tree->size);

    delete_node(tree, 'A');
    delete_node(tree, 'A');
    delete_node(tree, 'M');
    delete_node(tree, 'W');
    delete_node(tree, 'F');
    delete_node(tree, 'Y');

    subtree_iter(tree->root);
    printf("\nSize: %i\n", tree->size);

    next = subtree_find_next(tree->root, key);
    prev = subtree_find_previous(tree->root, key);

    if (next != NULL)
        printf("Node after %c: %c\n", key, next->item);
    if (prev != NULL)
        printf("Node before %c: %c\n", key, prev->item);

    binaryTree *test = create_binary_tree();
    test->root = build_from_array("ARTHURANDRADE", 0, 12);
    
    subtree_iter(test->root);
    printf("\n");

    free_tree(tree->root);
    free_tree(test->root);
    free(tree);
    free(test);
}
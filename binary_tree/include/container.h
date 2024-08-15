#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct node
{
    char item;
    struct node* parent;
    struct node* left;
    struct node* right;
}
node;

typedef struct 
{
    node *root;
    int size;
}
binaryTree;

node *create_node(char c);
binaryTree *create_binary_tree();
node *build_from_array(char *array, int start, int end);

#endif
#ifndef CONTAINER_H
#define CONTAINER_H

typedef struct node
{
    char item;
    int height;
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
void subtree_rotate_left(node *root);
void subtree_rotate_right(node *root);
void maintain(node *root);
void subtree_update(node *root);
int max(int a, int b);
void rebalance(node *root);
int skew(node *root);
int height(node *root);
void determine_new_root(binaryTree *tree);

#endif
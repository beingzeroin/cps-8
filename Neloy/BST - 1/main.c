#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main()
{
    BSTNode *root = NULL;
    root = rinsertBSTNode(root, 5);

    root = rinsertBSTNode(root, 3);
    root = rinsertBSTNode(root, 1);
    root = rinsertBSTNode(root, 4);

    root = rinsertBSTNode(root, 7);
    root = rinsertBSTNode(root, 6);
    root = rinsertBSTNode(root, 9);

    //print_ascii_tree(root);

    // Delete Root
        printf("%d ",searchBSTNode(root, 5)->data);

    print_ascii_tree(root);
    root = delteBSTNode(root, 4);
    print_ascii_tree(root);
    root = delteBSTNode(root, 3);
    print_ascii_tree(root);
    root = delteBSTNode(root, 5);
    print_ascii_tree(root);

    return 0;
}

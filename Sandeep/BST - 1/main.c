#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main()
{
    BSTNode *root = NULL,*t;
    root = insertBSTNode(root, 5);

    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 4);

    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 6);
    root = insertBSTNode(root, 9);

    print_ascii_tree(root);
    //t=searchBSTNode(root,4);
    //printf("\n%d",t->data);

    // Delete Root
    //root = delteBSTNode(root, 5);

    //print_ascii_tree(root);

    return 0;
}

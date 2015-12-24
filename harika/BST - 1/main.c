#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include<assert.h>s
int main()
{
    BSTNode *root = NULL;
    root = insertBSTNode(root, 5);
    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 4);

    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 6);
    root = insertBSTNode(root, 9);
    //assert(searchBSTNode(root,3)!=NULL);

    print_ascii_tree(root);

    // Delete Root
    root = deleteBSTNode(root, 5);
    print_ascii_tree(root);
    root = deleteBSTNode(root, 7);
    print_ascii_tree(root);
    root = deleteBSTNode(root, 3);
    print_ascii_tree(root);
    root = deleteBSTNode(root, 100);

    print_ascii_tree(root);

    return 0;
}

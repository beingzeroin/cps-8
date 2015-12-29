#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "BST.h"
#include <assert.h>
using namespace std;
int main()
{
    BSTNode *root=createBSTNode(10);
    root = insertBSTNode(root, 5);
    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 4);

    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 6);
    root = insertBSTNode(root, 9);
    //assert(searchBSTNode(root,3)!=NULL);

    print_ascii_tree(root);
    levelOrderTraversal(root);



    return 0;
}

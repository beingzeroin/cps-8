#include <cstdio>
#include <cstdlib>
#include "BST.h"
#include<cassert>

int main()
{
    BSTNode *root = NULL;
    root = createRandomTree(root,7);
    print_ascii_tree(root);
    printf("\n");
    spiralLevelOrder(root);
    return 0;
}

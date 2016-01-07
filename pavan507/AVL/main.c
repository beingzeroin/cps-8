#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
    AVLNode *root = NULL;

    root = insertAVL(root, 20);
    root = insertAVL(root, 30);
    root = insertAVL(root, 80);

    root = insertAVL(root, 40);
    root = insertAVL(root, 10);
    root = insertAVL(root, 60);
    root = insertAVL(root, 50);
    root = insertAVL(root, 70);

    prettyPrintAVL(root);
     inorderAVL(root);
    // prettyPrintAVL(root);


    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main()
{
    BSTNode *root = NULL;
    root=createRandomTree(root,10);
   /*root = insertBSTNode(root, 5);

    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 4);

    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 6);
   root = insertBSTNode(root, 9);
root = rinsertBSTNode(root,11);*/
    print_ascii_tree(root);
    if(isBST(root))
        printf("true\n");
    else
        printf("false");
  /*  if(searchBSTNode(root,10)!=NULL)
        printf("\nfound");
    else
        printf("\n not found");*/

    // Delete Root
 /* root = delteBSTNode(root, 5);
     print_ascii_tree(root);

   /* root = delteBSTNode(root, 7);
    print_ascii_tree(root);
      root=delteBSTNode(root,3);


     print_ascii_tree(root);
*/

    return 0;
}

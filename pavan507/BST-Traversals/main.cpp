#include <stdio.h>
#include <cstdlib>
#include "BST.h"
#include<assert.h>


int main()
{
    BSTNode *root1 = NULL,*root2=NULL,*root=NULL;
    root1 = insertBSTNode(root1, 5);
    root1 = insertBSTNode(root1, 3);
    root1 = insertBSTNode(root1, 1);
    root1= insertBSTNode(root1, 4);

    root1 = insertBSTNode(root1, 7);
    root1 = insertBSTNode(root1, 6);
    root1 = insertBSTNode(root1, 9);
    root1=insertBSTNode(root1,14);
    //assert(searchBSTNode(root,3)!=NULL);
root2=insertBSTNode(root2,13);
root2=insertBSTNode(root2,19);
root2=insertBSTNode(root2,11);
root=insertBSTNode(root,8);
/*root->left=root2;
root->right=root1;*/
    print_ascii_tree(root1);
    //printf("%d ",nodeCount(root1));
    //printf("\n%d ",height(root1));
  // printLevelOrder(root1);
    printf("\n");
   //root1= deleteBSTNode(root1,7);
    //print_ascii_tree(root1);
    printf("%d ",hasSum(root1,6));
    //printSpiralOrder(root1);
    //levelOrderTraversal(root);
    //printf("\n%d \n",height(root));

    //if(isBST(root1))
     //   printf("bst");
    //else
    //printf("not bst");
    //printf("\n spiral order\n");
//    spiralOrderTraversal(root);
  //  iterativePostorder(root);
    //recursiveInorder(root);
    // Delete Root
   /* root = rdeleteBSTNode(root, 5);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 7);
    print_ascii_tree(root);
    root = deleteBSTNode(root, 3);
    print_ascii_tree(root);
    root = rdeleteBSTNode(root, 100);

    print_ascii_tree(root);*/

    return 0;
}



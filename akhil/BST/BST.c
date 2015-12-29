#include "BST.h"
#include <stdlib.h>

BSTNode *createBSTNode(ElementType data)
{
    BSTNode *t = malloc(sizeof(BSTNode));
    t->left =NULL;
    t->right=NULL;
    t->data = data;
   return t;
}

BSTNode *rinsertBSTNode(BSTNode *root, ElementType data)
{
    if(root==NULL)
        return createBSTNode(data);
    if(data<root->data)
    {

       root->left= rinsertBSTNode(root->left,data);
    }
    else(data>root->data)
    {

        root->right= rinsertBSTNode(root->right,data);
    }

    return root;
}

BSTNode *insertBSTNode(BSTNode *root, ElementType data)
{

  if(root == NULL)
      return createBSTNode(data);
  BSTNode *c = root;
  while(1)
  {
      if(c->left=NULL&&c->data>data)
      {
          c->left=data;
      }
      c= c->left;
      else if(c->right==NULL&&c->data<data)
      {
          c->right=data;
      }
      c=c->right;
  }
  return c;
}
BSTNode *searchBSTNode(BSTNode* root,ElementType data)
{
    if(root->data==data||root->data==NULL)
        return root;
        if(data<root->data)
            return searchBSTNode(root->left,data);
        else
            return searchBSTNode(root->right,data);


}


BSTNode *delteBSTNode(BSTNode *root, ElementType data)
{
    if(root->data== data)
    {
     if(root->left ==NULL&&root->right==NULL)
     {
         free(root);
         return NULL;
     }
     else if(root->left==NULL||root->right==NULL)
     {
         if(root->left==NULL)
            return root->right;
         else
            return root->left;
     }

   else if(data<root->data)
        root->left = delteBSTNode(root->left,data);
        else
            root->right = delteBSTNode(root->right,data);
}


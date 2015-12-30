#include <queue>
#include <stack>
#include "BST.h"
using namespace std;
void iterativePostorder(BSTNode *r)
{
     stack<BSTNode*> mystack;
     stack *s = createStack();

     while(1)
     {
       while(r!=NULL)
       {

           mystack.push(r);
           r=r->left;
       }
       if(mystack.empty())
        break;
       r=mystack.top();
       mystack.pop();
       printf(" %d",r->data);

         r =r->right;

     }

}

void iterativePreorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
     stack *s = createStack();

     while(1)
     {
       while(r!=NULL)
       {
           printf(" %d",r->data);
           mystack.push(r);
           r=r->left;
       }
       if(mystack.empty())
        break;
       r=mystack.top();
       mystack.pop();

         r =r->right;

     }

}

void iterativeInorder(BSTNode *r)
      if(r==NULL)
          return;
      stack<BSTNode*> mystack;
 while(1)
 {
     while(r!=NULL)
     while(1)
      {
         mystack.push(r);
         r=r->left;
         while(r!=NULL)
         {
             mystack.push(r);
             r=r->left;

         }
         if(mystack.empty())
            break;
         r=mystack.top();
         printf("%d ",r->data);
 mystack.pop();
         r=r->right;

      }
     if(mystack.empty())
     break;
     r=mystack.top();
     printf("%d ",r->data);
     mystack.pop();
    r=r->right;
 }
int isBST(BSTNode *root)
{
    if(root==NULL)
        return ;
    if(root!=NULL)
    {
        if(root->left->data<root->data&&root->right->data>root->data)
        {
            isBST(root->left)

        }
    }

}

void LevelOrder(BSTNode *root)
{
    queue<BSTNode *> q;
    BSTNode *temp;

    if(root==NULL)
        return ;
        q.push(root);
        while(1)
        {
            is(q.empty())
             break;
             temp = q.front();
             printf("%d",temp->data);
             q.pop();
             if(temp->left!=NULL)
                q.push(temp->left);
             else if(temp->right!=NULL)
                q.push(temp->right);

         }


}
void LevelOrderspiral(BSTNode *r)
{
if(r==NUll)
    return ;

queue<BSTNode *>q


}


bool hasSum(BSTNode *r,int sum)
{
    if(r->data == sum && r->left == NULL && r->right)
}





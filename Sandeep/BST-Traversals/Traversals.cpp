#include <stack>
#include "BST.h"
using namespace std;

void iterativePreorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
     Stack *s=createStack();
     while(1)
     {
         while(r!=NULL)
         {

             printf("%d",r->data);
             mystack.push(r);
             r=r->left;
         }
         if(myStack.empty())
            break;
         r=myStack.top();
         myStack.pop();
         r=r->right;
     }

}
void iterativeInorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    Stack *s=createStack();
    while(1)
    {
       while(r!=NULL)
       {
        mystack.push(r);


       }

    }




}

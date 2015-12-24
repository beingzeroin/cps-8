#include <stack>
#inclue<BST.h>
using namespace std;

void iterativePreorder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    stack *s=createstack;

    while(1)
    {
        while(r!=NULL)
        {
          printf("%d ",r->data);
          mystack.push(r);
          r=r->left;
        }
        if(mystack.empty())
        break;
        r=mysatck.top();
        mystack.pop();
        r=r->right;
    }
}

void iterativeinorder(BSTNode *r)
{
  stack<BSTNode>mystack;
  stack *s=createstack();
  while(1)
  {
      while(r!=NULL)
      {
        printf("%d ",r->data);
        mystack.push(r);
        r=r->right;
      }

      if(mystack.empty())
        break;
      r=mystack.top();
      mystack.pop();
  }
}




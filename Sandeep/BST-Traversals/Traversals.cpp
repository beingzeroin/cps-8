#include <stack>
#include "BST.h"
#include <cstdlib>
#include <cstdio>

using namespace std;

void iterativeInorder(BSTNode *r)
{

    stack<BSTNode*> mystack;
    while(1)
    {
        while(r!=NULL)
        {
/*            if(r->right!=NULL)
                mystack.push(r->right);
                */
            mystack.push(r);
            r= r->left;

        }
         if(mystack.empty())
            break;
        r = mystack.top();
        printf(" %d",r->data);
        mystack.pop();


        r = r->right;
    }

}
void iterativePostrder(BSTNode *r)
{
    stack<BSTNode*> mystack;
    BSTNode *p, *rc;
    while(1)
    {
        while(r!=NULL)
        {
            if(r->right!=NULL)
                mystack.push(r->right);

            mystack.push(r);
            r = r->left;
        }

        if(mystack.empty())
            break;
        p = mystack.top();
        mystack.pop();

        if(mystack.empty())
        {
            printf("%d ", p->data);
            break;
        }
        rc = mystack.top();
        mystack.pop();


        if(rc == p->right)
        {
            mystack.push(p);
            r = rc;
        }
        else
        {
            printf("%d ", p->data);
            mystack.push(rc);
            r = NULL; // IMPORTANT THING
        }
    }
}
void iterativePreorder(BSTNode *r)
{
    stack<BSTNode*> mystack;

    while(1)
    {
        while(r!=NULL)
        {
            printf("%d ", r->data);
            mystack.push(r);
            r = r->left;
        }

        if(mystack.empty())
            break;
        r = mystack.top();
        mystack.pop();

        r = r->right;
    }

}

/*

// Take a Stack
Stack *s = createStack();

while(1)
{
	// Keep pushing and printing Elements
	// move root = root->left
	// until we reach NULL

	// BREAK if Stack is Empty
	// Pop
	root = pop(s);

	// Start the procedure again from Right
	root = root->right;
}

s = destroyStack();
*/

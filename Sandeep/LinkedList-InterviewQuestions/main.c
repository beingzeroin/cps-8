#include "LLNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LLNode *reverseRecursive1(LLNode *first)
{
   if(first == NULL || first->next == NULL) return first; // list with only one node.

   LLNode *rest = reverseRecursive1(first->next); // recursive call on rest.

   first->next->next= first; // make first; link to the last node in the reversed rest.

   first->next = NULL; // since first is the new last..make its link NULL.

   return rest; // rest now points to the head of the reversed list.
}

LLNode *reverseRecursive(LLNode *h1, LLNode *p)
{
    if(h1==NULL)
        return NULL;
    if(h1->next==NULL)
    {
        h1->next = p;
        return h1;
    }

    LLNode *l = reverseRecursive(h1->next, h1);
    h1->next = p;
    return l;
}


int main()
{
<<<<<<< HEAD
    // EXERCISE-1
    // Implement - findIntersectionPoint - in InterviewQuestions.c
    // intersectionUnitTests();

    // EXERCISE-2
    // Implement - getKthNodeFromEnd - in InterviewQuestions.c
<<<<<<< HEAD
    // kthNodeFromEndUnitTests();
    LLNode *h=createSerialList(1,10);
       traverse(h);
       LLNode *k=reverseLinkedList(h);
       traverse(k);
=======
     //kthNodeFromEndUnitTests();
     //hasCycleUnitTests();

    // if(hasCycles(h))
      //  printf("*");
    LLNode *h=createSerialList(1,5);
    //LLNode *temp=findLastNode(h);
    h=reverseLinkedList(h);
    traverse(h);
>>>>>>> f32f847bdaedc490da3af20f218f3ddacad191e1
==========
    LLNode *h = NULL;
    int n, v;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &v);
        h = insertInEnd(h, v);
    }

    //h = reverseRecursive(h, NULL);
    h = reverseRecursive(h, NULL);
    traverse(h);

>>>>>>> a6307bfd13d2d91e66b8999a382c3d61938c6ae4
    return 0;

}

#include "LLNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main()
{
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
    return 0;
}

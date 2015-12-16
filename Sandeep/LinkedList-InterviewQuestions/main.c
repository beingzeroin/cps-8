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
     //kthNodeFromEndUnitTests();
     //hasCycleUnitTests();

    // if(hasCycles(h))
      //  printf("*");
    LLNode *h=createSerialList(1,5);
    //LLNode *temp=findLastNode(h);
    h=reverseLinkedList(h);
    traverse(h);
    return 0;
}

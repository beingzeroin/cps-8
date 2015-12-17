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
    // kthNodeFromEndUnitTests();
    LLNode *h=createSerialList(1,10);
       traverse(h);
       LLNode *k=reverseLinkedList(h);
       traverse(k);
    return 0;
}

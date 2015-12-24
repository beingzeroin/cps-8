#include "LLNode.h"
#include <assert.h>
#include <stdlib.h>

void intersectionUnitTests()
{
    // 1->2->3->4->5->6
    // 9->4->5->6
    LLNode *common = createSerialList(4, 6);
    LLNode *first = createSerialList(1, 3);
    LLNode *second = createSerialList(9, 9);

    findLastNode(first)->next = common;
    findLastNode(second)->next = common;

    LLNode *ip = findIntersectionPoint(first, second);
    assert(ip!=NULL && ip->data==4);

    LLNode *third = createSerialList(10, 14);
    LLNode *ip2 = findIntersectionPoint(first, third);
    assert(ip2==NULL);

    assert(findIntersectionPoint(NULL, NULL)==NULL);
    assert(findIntersectionPoint(first, NULL)==NULL);
    assert(findIntersectionPoint(NULL, third)==NULL);
}


void kthNodeFromEndUnitTests()
{
    LLNode *h = createSerialList(1, 10);
    LLNode *kth = NULL;
    int k;
    for(k=1;k<=10;k++){
        kth = getKthNodeFromEnd(h, k);
        assert(kth!=NULL);
        assert(kth->data == 10-k+1);
    }

    assert(getKthNodeFromEnd(h, 15)==NULL);
    assert(getKthNodeFromEnd(NULL, 3)==NULL);
}

LLNode *getKthFromBeginning(LLNode *h, int k)
{
    int i;
    for(i=1;i<k;i++)
        h = h->next;
    return h;
}

void hasCycleUnitTests()
{
    LLNode *h = createSerialList(1, 10);
    assert(hasCycle(h)==false);

    LLNode *randomNode ;
    LLNode *lastNode = findLastNode(h);

    int i;
    for(i=1;i<=10;i++)
    {
        randomNode = getKthFromBeginning(h, rand()%11);
        lastNode->next = randomNode;
        assert(hasCycle(h)==true);
        lastNode->next = NULL;
        assert(hasCycle(h)==false);
    }
}

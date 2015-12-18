void kthNodeFromEndUnitTests()
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
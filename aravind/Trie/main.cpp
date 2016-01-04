#include <iostream>
#include "trie.h"
#include <stdio.h>
#include <assert.h>

using namespace std;

int unitTests()
{
    TNode *root = createTrieNode();

    insertWordInTrie(root, "beingzero");
    insertWordInTrie(root, "apple");
    insertWordInTrie(root, "apple");
    insertWordInTrie(root, "banana");
    insertWordInTrie(root, "chiku");
    insertWordInTrie(root, "car");
    insertWordInTrie(root, "cart");
    insertWordInTrie(root, "carts");

    printWordsInTrie(root);
    cout<<endl;
    deleteFromTrie(root, "apple");

    printWordsInTrie(root);
    return 0;
}

int main()
{
    TNode *root = createTrieNode();
    FILE *fp = fopen("dictionary.txt","r");
    assert(fp!=NULL);
    char word[1000];

    while(!feof(fp))
    {
        fscanf(fp, "%s", word);
        insertWordInTrie(root, word);
    }

    fclose(fp);

    printWordsInTrie(root);

    return 0;
}

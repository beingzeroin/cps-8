#include <iostream>
#include "trie.h"
#include <stdio.h>
#include <assert.h>

using namespace std;

int unitTests()
{
    TNode *root = createTrieNode();


    rinsertWordInTrie(root, "apple");
    rinsertWordInTrie(root, "car");
    rinsertWordInTrie(root, "cars");
    rinsertWordInTrie(root, "cart");
    rinsertWordInTrie(root, "carts");

    /*
    rinsertWordInTrie(root, "beingzero");

    rinsertWordInTrie(root, "apple");
    rinsertWordInTrie(root, "banana");
    rinsertWordInTrie(root, "chiku");
    rinsertWordInTrie(root, "car");
    rinsertWordInTrie(root, "cart");
    rinsertWordInTrie(root, "carts");
*/
    printWordsInTrie(root);

    /*deleteWordFromTrie(root, "apple");
    deleteWordFromTrie(root, "car");
    deleteWordFromTrie(root, "carts");
    deleteWordFromTrie(root, "zoo");
    deleteWordFromTrie(root, "ca");
    */
    deleteWordFromTrie(root, "cart");
    deleteWordFromTrie(root, "");

    printf("\n\n");
    printWordsInTrie(root);

    return 0;
}

int main()
{
    TNode *root = createTrieNode();

    FILE *fp = fopen("dictionary.txt", "r");
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

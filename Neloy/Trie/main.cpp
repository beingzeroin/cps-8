#include <stdio.h>
#include "Trie.h"
using namespace std;

int main()
{
    char word[]="cab";
    TNode *root = createTrieNode();
    printf("\n%d",rinsertWordInTrie(root,word));
    printf("\n%d",rinsertWordInTrie(root,"ca"));
    printf("\n%d\n",rinsertWordInTrie(root,"thehulk"));
    printWordInTrie(root);
    //printf("\n%d\n",deleteWordFromTrie(root,"cab"));
    //printWordInTrie(root);
    printf("%d %d %d %d\n",hasWord(root,"cab"),hasWord(root,"ca"),hasWord(root,"ironman"),hasWord(root,"thehulk"));
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

char text[10000];

int main()
{
    int i = 0;
    bool isFirstQuote = true;
    char ch;
    while((ch = getchar()) != EOF){
        if(ch == 34 && isFirstQuote){
            printf("``");
            isFirstQuote = false;
        }
        else if(ch == 34 && !isFirstQuote){
            printf("''");
            isFirstQuote = true;
        }
        else
            printf("%c",ch);
    }
    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[10000];

char *reverse(char *s){
    int i = 0, j = strlen(s) - 1;
    char ch;
    while(i < j){
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
        i++;j--;
    }
    return s;
}
int main()
{
    char word[1000],ch;
    int i = 0, j = 0;
    while((ch = getchar()) != EOF)
        input[i++] = ch;
    input[i] = '\0';
    i = 0;
    while(input[i] != '\0'){
        if(isprint(input[i]) && !isspace(input[i]))
            word[j++] = input[i++];
        else{
            word[j] = '\0';
            printf("%s",reverse(word));
            printf("%c",input[i++]);
            j = 0;
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

void permutationResult(char *,int,int);
void sort(char *);
void swap(char *,char *);

long n = 0;
int FLAG = 1;

int main()
{
    long testcases;
    scanf("%ld",&testcases);
    while(testcases--){
        char s[21];
        scanf("%s",s);
        scanf("%ld",&n);
        sort(s);
        permutationResult(s,strlen(s)-1,0);
        FLAG = 1;
    }
    return 0;
}

void permutationResult(char *s,int length,int fix){
    int i;
    char temp_string[21];
    strcpy(temp_string,s);
    if(fix == length){
        if(n == 0){
            FLAG = 0;
            printf("%s\n",s);
        }
        else{
            /*printf("Temporary string : %s\n",s);*/
            n--;
        }
    }
    else{
        for(i = fix;i <= length; i++){
            swap(&temp_string[i],&temp_string[fix]);
            permutationResult(temp_string,length,fix+1);
            if(FLAG == 0)
                return;
        }
    }
}
void sort(char *s){
    long length = strlen(s);
    long i = 0, j = 0;
    for(i = 0;i < length-1;i++)
        for(j = i + 1;j < length;j++)
            if(s[i] > s[j]){
                char ch = s[i];
                s[i] = s[j];
                s[j] = ch;
            }
}
void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}


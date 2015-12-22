#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char arr[300];
int push(char s,int top)
{
    top++;
    arr[top]=s;
    return top;
}
int pop(int top)
{
    top--;
    return top;
}
char peek(int top)
{
    return arr[top];
}

int main()
{
    char str[200];
    int i,flag,n,top;
    scanf("%d\n",&n);
    bool isMatching = true;
    while(n--)
    {
        i=0;
        flag=0;
        top=-1;
        scanf("%[^\n]%c",str);
        isMatching = true;
        for(i=0; str[i]!='\0'; i++)
        {
            if(isspace(str[i]))
                continue;

            if(str[i]=='(' || str[i]=='[')
            {
                top=push(str[i],top);
                continue;
            }

            if(top==-1)
            {
                isMatching = false;
                break;
            }

            if(str[i]==')')
            {
                if(peek(top)=='(')
                    top= pop(top);
                else
                {
                    isMatching = false;
                    break;
                }
            }
            else if(str[i]==']')
            {
                if(peek(top)=='[')
                    top=pop(top);
                else
                {
                    isMatching = false;
                    break;
                }
            }
        }

        if(top==-1 && isMatching)
            printf("Yes\n");
        else
            printf("No\n");


    }
    return 0;
}

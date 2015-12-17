#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int checkBalance(char *s)
{
    int len = strlen(s);
    int i,j,cnt=0,pcnt=0;
    while(1)
    {
        for(i=0;i<len-1;i++)
        {
            pcnt=cnt;
            if(s[i]=='(')
            {
                j=i+1;
                while(j=='0')
                    j++;
                if(s[j]==')')
                {
                    s[i]='0';
                    s[j]='0';
                    cnt+=2;
                }
            }
            else if(s[i]=='[')
            {
                j=i+1;
                while(j=='0')
                    j++;
                if(s[j]==']')
                {
                    s[i]='0';
                    s[j]='0';
                    cnt+=2;
                }
            }
            else
                continue;
            if(pcnt==cnt)
                return 0;
            else if(cnt==strlen(s))
                return 1;
        }
    }
}
*/

char stack[200];

int top;

void push(char c)
{
    stack[++top]=c;
}

void pop()
{
    top--;
}

char peek()
{
    return stack[top];
}

int checkBalance(char *s)
{
    top=-1;
    int i,len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]=='[')
            push(s[i]);
        else
        {
            if((s[i]==')' && peek()=='(')||(s[i]==']' && peek()=='['))
                pop();
            else
                return 0;
        }
    }
    if(top==-1)
        return 1;
    else
        return 0;
}


int main()
{
    int n;
    scanf("%d\n",&n);
    int i;
    char s[200];
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        if(checkBalance(s))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

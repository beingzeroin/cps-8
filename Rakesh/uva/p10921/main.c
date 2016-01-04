#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[30];
    while(scanf("%s",input)>0)
    {
        int i=0;
        for(; input[i]!='\0'; i++)
        {
            if(input[i]=='-')
                printf("-");
            else if(input[i]=='1')
                printf("1");
            else if(input[i]=='0')
                printf("0");
            /*else if(input[i]=='A' || input[i]=='B' || input[i]=='C')
                printf("2");
            else if(input[i]=='D' || input[i]=='E' || input[i]=='F')
                printf("3");
            else if(input[i]=='G' || input[i]=='H' || input[i]=='I')
                printf("4");
            else if(input[i]=='J' || input[i]=='K' || input[i]=='L')
                printf("5");
            else if(input[i]=='M' || input[i]=='N' || input[i]=='O')
                printf("6");
            else if(input[i]=='P' || input[i]=='Q'  || input[i]=='R' || input[i]=='S')
                printf("7");
            else if(input[i]=='T' || input[i]=='U' || input[i]=='V')
                printf("8");
            else if(input[i]=='W' || input[i]=='X' || input[i]=='Y' || input[i]=='Z')
                printf("9");*/
            else
            {
                int j=65,k=0;
                for(; j<91; j++)
                    if(input[i]==(char)j)
                    {
                        k=j-65;
                        if(k>=18)
                            k--;
                        k=k/3;
                        if(k==8) k--;
                        printf("%d",2+k);
                    }
            }
        }
        input[0]='\0';
        printf("\n");
    }
    return 0;
}

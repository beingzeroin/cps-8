#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;


void printCharsToNumbers(char str[])
{
    int i;
    printf("%d\n", strlen(str));
    for(i=0;str[i]!='\0';i++)
        {
            if(isalpha(str[i]) && islower(str[i]))
                printf("%d ", str[i]-'a');
            else if(str[i]=='\n')
                printf("-1 ");
            else if(str[i]==' ')
                printf("-2 ");
            else if(str[i]=='.')
                printf("-3 ");
            else assert(false);
        }
}
void printNumbersToChars()
{
    int n, ci;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &ci);
        if(ci==-1)
            printf("\n");
        else if(ci==-2)
            printf(" ");
        else if(ci==-3)
            printf(".");
        else
            printf("%c", ci+'a');
    }
}
int main()
{
    char str[] = "our love grows with every passing moment.  will see you soon.\n\nwith lots of love\nsimran.";

    char str1[] = "i\nlove\nyou.";
    char str2[2000] = "no one bring so much happiness to my life as you. in your company i find love that i have never known before. i can not imagine what my life would be without you. i want to spend the rest of my life with you. you have given me so much love and encouragement that i dont think i will be able to return all that to you. you have been lighting up the dark and bringing joy to my heart. when i am with you i feel alive and strong. i am truly blessed to have you as a part of my life and i cannot wait for the day when we start a new life. when i say i love you. i mean every word of it.\nyours\nsimran.";
    //printCharsToNumbers(str2);
    char str3[5000] = "dear raj\n\nlet me start by saying that i thank god every night since i found you. you came into my life when everything seemed so dark but you provided the light to find my way. i have never been so certain of anything in my life like i am of us. you have totally changed my outlook in life and i thank you for that. i never thought that someone could love me like you do. but guess what i love you that much too. i feel as if i am walking over clouds just thinking about you. you make my life complete. i know you have said we could do foolish things while in love. but you know what with you i would not mind being a fool for the rest of my life. i love you so much and i know you love me too. i know that others looking into our relationship might think that we are saying too many foolish things too soon but they just dont know how we feel about each other. there is nothing foolish about the things i have told you. i meant every word i said. \n\ni love you. \n\n\ni would do anything. i love you so much. today i promise you that i would do anything in my power to make you a great person outstanding lover and supportive partner.\n\nyours\nsimran.";
    char str4[] = "i love you.\nsimran.";
    //printCharsToNumbers(str4);
    printNumbersToChars();
    return 0;
}

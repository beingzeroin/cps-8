#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char a[3][3];
int x,y,xcount,ocount;
void scanInput();
bool testInput();
bool isGame(char);
int main()
{
    int n;
    scanf("%d",&n);
    while(n>0)
    {
        scanInput();
        if(testInput())
            printf("yes");
        else
            printf("no");
            n--;
    }
    return 0;
}
void scanInput()
{
    for(x=0; x<3; x++)
        scanf("%c %c %c",&a[x][0],&a[x][1],&a[x][2]);
}
bool testInput()
{
    xcount=0;
    ocount=0;
    for(x=0; x<3; x++)
        for(y=0; y<3; y++)
        {
            if(a[x][y]=='X')
                xcount++;
            else if(a[x][y]=='O')
                ocount++;
        }
    if(ocount==xcount)
    {
        return !isGame('X');
    }
    if(ocount==xcount-1 )
    {
        return !isGame('O');
    }
    return false;
}
bool isGame(char ch)
{
    for(x=0; x<3; x++)
        if(a[x][0]==ch && a[x][1]==ch && a[x][2]==ch)
            return true;
    for(x=0; x<3; x++)
        if(a[0][x]==ch && a[1][x]==ch && a[2][x]==ch)
            return true;
    if(a[0][0]==ch && a[1][1]==ch && a[2][2]==ch)
        return true;
    if(a[0][2]==ch && a[1][1]==ch && a[2][0]==ch)
        return true;
    return false;
}

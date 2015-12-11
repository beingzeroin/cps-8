#include<stdio.h>
#include<conio.h>
#include<time.h>
void print(int m,int n,int mines,int a[100][100])
{
int i,j,k,s;

srand(time(NULL));
for(i=0;i<mines;i++)
{
j=rand()%(m);
k=rand()%(m);printf("%d %d\n",j,k);
if(a[j][k]==1)
{
i--;
}
else
{
a[j][k]=1;
}
}
for(i=0;i<m;i++)
{ printf("\n");
for(s=0;s<n;s++)
{printf("%d ",a[i][s]);}
}
}
int main()
{
int m,n,mines,a[100][100],i,s;
clrscr();
printf("enter the size of the board-rows and columns: ");
scanf("%d %d",&m,&n);
printf("enter the no of mines: ");
scanf("%d",&mines);
for(i=0;i<m;i++)
for(s=0;s<n;s++)
a[i][s]=0;
print(m,n,mines,a);
getch();
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
int totalFingers(int n)
{
    if(n==0)
        return 0;
    if(n%2==0)
        return 11+totalFingers(n-1);
    else
        return 10+totalFingers(n-1);



}
int sum(int n)
{
    if(n==0)
        return 0;
    else
        return n%10+sum(n/10);

}
void reverse(char a[],int s,int e)
{
    char t;
    if((s-e)>=0)
        return;
    t=a[s];
    a[s]=a[e];
    a[e]=t;
    reverse(a,s+1,e-1);

}
bool hasNumber(int a[],int n,int key)
{
    if(n<0)
        return false;
    if(a[n]==key)
        return true;
    return hasNumber(a,n-1,key);

}

int main()
{
    int n,key,i;
    int  a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("enetr key\n");
        scanf("%d",&key);
    printf("%d",hasNumber(a,n-1,key));
    //printf("number of people\n");
    //scanf("%d",&n);
    //printf("%d\n",totalFingers(n));
    //printf("%d\n",sum(n));
   // reverse(a,0,strlen(a)-1);
    //printf("%s ",a);
    return 0;
}

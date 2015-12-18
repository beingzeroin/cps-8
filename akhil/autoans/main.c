#include <stdio.h>
#include <stdlib.h>
double a[20],ans[20];
int i,t;
int autoAnsGen(int a[10])
{
 for(i=0;i<t;i++)
 {

 ans[i]=(((((((a[i]*567)/9)+7492)*235)/47)-498)%100);
 }

    return 0;
}



int main()
{

    printf("enter the no. of testcases : \n");
    scanf("%d",&t);
    printf("\n Enter the value for each test case: ");

    for(i=0;i<t;i++)
    {
    scanf("%d",a[i]);
    }


    autoAnsGen(a);

    for(i=0;i<t;i++)
    {
    printf("%d \n",ans[i]);
    }

    return 0;
}

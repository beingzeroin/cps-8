#include <stdio.h>
#include <stdlib.h>
long toSecc(int);
int main()
{
   long t,secc;
   float f=1000.f/864.f;
   printf("%f\n",f);
   while(scanf("%li",&t)>0)
   {
       secc=toSecc(t);
       secc=f*secc;
       printf("%li",secc);
   }
    return 0;
}
long toSecc(int t)
{
    int hh=(t/1000000);
    int mm=(t-hh*1000000)/10000;
    int ss=(t%10000)/100;
    return hh*60*60*100+mm*60*100+ss*100+t%100;
}

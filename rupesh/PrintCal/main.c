#include <stdio.h>
#include <stdlib.h>
int daysInMonth[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char month[13][20]=
{
"",
"January",
"February",
"March",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December"
};

void PrintCalender(int y,int m)
{
    int firstday,i,flag,NoOfDays=0;
    printf("%d %s",y,month[m]);
    printf("\n\nSUN MON TUE WED THU FRI SAT\n");
    firstday=determineFirstDayOfYear(y);
     if(y%4==0)
     {
        daysInMonth[2]++;
        flag=1;
     }
     for(i=1;i<m;i++)
     {
         NoOfDays=NoOfDays+month[i];
     }
     firstday= firstday+NoOfDays;
     firstday=(firstday)%7;
     for(i=0;i<firstday;i++)
     {
         printf("    ");
     }
     for(i=1;i<=daysInMonth[m];i++)
     {
         printf("%3d ",i);
         if((i+firstday)%7==0)
         {
             printf("\n");
         }
     }
     if(flag==1)
     {
         daysInMonth[2]--;
     }
}
int determineFirstDayOfYear(int year)
{
 int d1, d2, d3;
 d1 = (year - 1.)/ 4.0;
 d2 = (year - 1.)/ 100.;
 d3 = (year - 1.)/ 400.;
 return (year + d1 - d2 + d3) %7;
}
int main()
{

    PrintCalender(2009,2);

    return 0;
}

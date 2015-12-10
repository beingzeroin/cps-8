#include<stdio.h>
int daysInMonth[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char months[13][20]=
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
/* Returns 0 – SUN, 1 – MON, ... , 6 – SAT */
int determineFirstDayOfYear(int year)
{
 int d1, d2, d3;
 d1 = (year - 1.)/ 4.0;
 d2 = (year - 1.)/ 100.;
 d3 = (year - 1.)/ 400.;
 return (year + d1 - d2 + d3) %7;
}
int isLeap(int y)
{
    int flag=0;
    if(y%4 == 0)
      {
          if( y%100 == 0) /* Checking for a century year */
              if ( y%400 == 0)
                 flag=1;
          else
             flag=1;
      }
    return flag;
}
void printcal(int m,int y)
{
    int i,fdm,dim,flag=0;
    int fdy=determineFirstDayOfYear(y);
    for(i=1;i<m;i++)
        fdm+=daysInMonth[i];
    flag=isLeap(y);
    if(flag==0)
      fdm=(fdm+fdy+1)%7;
    else if(flag==1)
    {
        if(m>2)
            fdm=(fdm+fdy+2)%7;
        else
            fdm=(fdm+fdy+1)%7;
    }
    printf("%s %d\n",months[m],y);
    printf("SUN MON TUE WED THU FRI SAT\n");
    dim=daysInMonth[m];
    for(i=0;i<fdm;i++)
        printf("%4s","");
    for(i=1;i<=dim;i++)
    {
        printf("% 3d ",i);
        if((i+fdm)%7==0)
            printf("\n");
       // i++;
    }
}
int main()
{
    int m,y;
    scanf("%d",&m);
    scanf("%d",&y);
    printcal(m,y);
    return 0;
}

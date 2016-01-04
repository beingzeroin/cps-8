#include<stdio.h>
#include<stdlib.h>
int determineFirstDayOfYear(int year)
{
    int d1, d2, d3;
    d1 = (year - 1.)/ 4.0;
    d2 = (year - 1.)/ 100.;
    d3 = (year - 1.)/ 400.;
    return (year + d1 - d2 + d3) %7;
}

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

int firstdayofmonth(int fd,int m)
{
    int i,sum=fd;
    for(i=1;i<m;i++)
        sum+=daysInMonth[i];
    sum=sum%7;
    return sum;
}

void cal(int y,int m)
{
    int fdm,fd,yy=y,mm=m,i;
    if(yy%4==0)
        daysInMonth[2]=29;
    fd=determineFirstDayOfYear(yy);
    fdm=firstdayofmonth(fd,mm);
    printf("SUN MON TUE WED THU FRI SAT\n");
    for(i=1;i<=daysInMonth[mm];i++)
    {
        if(i==1)
        {
            switch(fdm)
        {
            case 0:printf("%3d",i);break;
            case 1:printf("%7d",i);break;
            case 2:printf("%11d",i);break;
            case 3:printf("%15d",i);break;
            case 4:printf("%19d",i);break;
            case 5:printf("%23d",i);break;
            case 6:printf("%27d",i);break;
        }
        }
        else{
            if((fdm+i-1)%7==0)
            {
                printf("\n%3d",i);
            }
            else
                printf("%4d",i);
        }
    }
}

int main()
{
    int month,year;
    printf("Enter the year and month\n");
    scanf("%d %d",&year,&month);
    printf("\n\n\t%d\t%s\n\nyear,months[month]);
    cal(year,month);

}

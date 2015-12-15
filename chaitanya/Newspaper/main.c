#include <stdio.h>
#include <stdlib.h>

typedef struct paid_character
{
    char ch;
    int value;
}charcter;

typedef struct price
{
    int absicca;
    int ordinate;
}prices;


long int checkInList(char *str,charcter list[20],int n)
{
    long int i=0,j,count=0;
    while(str[i]!='\0')
    {
      for(j=0;j<n;j++)
      {
          if(str[i]==list[j].ch)
          {
          count+=list[j].value;
          break;
          }

      }

    i++;
    }
    return count;
}
int main()
{
    int test_cases,char_lines,ch1,absicca,ordinate,l=0;
      long int dollars,para_lines,i,j,k;
    char str[100001],temp[200],ch,dummy[150001];
    charcter list[100];
    prices p[101];
      scanf("%[^\n]%*c",dummy);
      test_cases=atoi(dummy);
      while((test_cases)--)
      {
        dollars=0;i=0;
         scanf("%[^\n]%*c",dummy);
         char_lines=atoi(dummy);
         if(char_lines!=0)
         {
          while((char_lines)--)
          {
              fgets(str, sizeof(str), stdin);
              list[i].ch=str[0];
              for(j=2,k=0;str[j]!='\0';j++,k++)
              {
                  temp[k]=str[j];
              }
              temp[k]='\0';
              list[i].value=atoi(temp);
              i++;
          }
         }
       scanf("%[^\n]%*c",dummy);
        para_lines=atoi(dummy);
          while((para_lines)--)
          {
              fgets(str, sizeof(str), stdin);
            dollars+=checkInList(str,list,i);
          }
        p[l].absicca=dollars/100;
        p[l].ordinate=dollars%100;
       l++;
}
      for(i=0;i<l;i++)
      {
           if(p[i].ordinate<10)
        {
            if(i!=l-1)
            {
            printf("%d.%d0$\n",p[i].absicca,p[i].ordinate);
            }
            else
            printf("%d.%d0$",p[i].absicca,p[i].ordinate);

        }
        else
        {
          if(i!=l-1)
            {
            printf("%d.%d$\n",p[i].absicca,p[i].ordinate);
            }
            else
        printf("%d.%d$",p[i].absicca,p[i].ordinate);
       }
      }
    return 0;
}

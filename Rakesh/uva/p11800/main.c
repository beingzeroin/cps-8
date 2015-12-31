#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int coordinates[4][2];
char* getShape();
int main()
{
    int t,i,j;
    scanf("%d",&t);
    for(j=0; j<t; j++)
    {
        for(i=0; i<4; i++)
            scanf("%d %d",&coordinates[i][0],&coordinates[i][1]);
        printf("Case %d: %s\n",j+1,getShape());
    }
    return 0;
}
char* getShape()
{
    float s[4],m[4];
    int i,a=-1;
    for(i=0; i<3; i++)
    {
        s[i]=sqrt(pow((coordinates[i+1][0]-coordinates[i][0]),2)+pow((coordinates[i+1][1]-coordinates[i][1]),2));
        if((coordinates[i+1][0]!=coordinates[i][0]) && coordinates[i+1][1]!=coordinates[i][1])
            m[i]=(coordinates[i+1][1]-coordinates[i][1])/(coordinates[i+1][0]-coordinates[i][0]);
        else
        {
            a=a*-1;
            m[i]=a;
        }
    }
    s[i]=sqrt(pow((coordinates[0][0]-coordinates[i][0]),2)+pow((coordinates[0][1]-coordinates[i][1]),2));
    if((coordinates[0][0]!=coordinates[i][0]) && (coordinates[0][1]!=coordinates[i][1]))
        m[i]=(coordinates[0][1]-coordinates[i][1])/(coordinates[0][0]-coordinates[i][0]);
    else
    {
        a=a*-1;
        m[i]=a;
    }
    if(s[1]==s[2] && s[1]==s[3] && s[1]==s[0] && m[0]*m[1]==-1)return "Square";
    else if(s[1]!=s[2] && s[1]==s[3] && s[2]==s[0] && m[0]*m[1]==-1)return "Rectangle";
    else if(s[1]==s[3] && s[2]==s[0] )return "Parallelogram";
    else if(s[1]==s[2] && s[1]==s[3] && s[1]==s[0])return "Rhombus";
    else if(m[1]==m[3] || m[2]==m[0])return "Trapezium";
    else return "Ordinary Quadrilateral";
}

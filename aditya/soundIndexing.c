#include <stdio.h>
#include <stdlib.h>
char name[10000][100], codes[10000][100];
int main()
{
    char ch;
    int n = 0, i = 0, j = 0, ci = 0, cj = 0, flag = 0;
    while((ch = getchar()) != EOF){
        if(ch == '\n'){
            name[n][j] = '\0';
            n++;
            j = 0;
        }
        else
            name[n][j++] = ch;
    }
    while(i <= n){
        j = 0;cj = 0;
        if(name[i][j] != '\0'){
            codes[ci][cj++] = name[i][j];
            if(name[i][j] == 'B' || name[i][j] == 'P' || name[i][j] == 'F' || name[i][j] == 'V')
                flag = 1;
            else if(name[i][j] == 'C' || name[i][j] == 'S' || name[i][j] == 'K' || name[i][j] == 'G' || name[i][j] == 'J' || name[i][j] == 'Q' || name[i][j] == 'X' || name[i][j] == 'Z')
                flag = 2;
            else if(name[i][j] == 'D' || name[i][j] == 'T')
                flag = 3;
            else if(name[i][j] == 'L')
                flag = 4;
            else if(name[i][j] == 'M' || name[i][j] == 'N')
                flag = 5;
            else if(name[i][j] == 'R')
                flag = 6;
            else if(name[i][j] == 'A' || name[i][j] == 'E' || name[i][j] == 'I' || name[i][j] == 'O' || name[i][j] == 'U' || name[i][j] == 'Y' || name[i][j] == 'W' || name[i][j] == 'H')
                flag = 7;
            j++;
        }
        while(name[i][j] != '\0'){
            if(cj > 3)
                break;
            if(flag != 1 && (name[i][j] == 'B' || name[i][j] == 'P' || name[i][j] == 'F' || name[i][j] == 'V')){
                codes[ci][cj++] = '1';
                flag = 1;
            }
            else if(flag != 2 && (name[i][j] == 'C' || name[i][j] == 'S' || name[i][j] == 'K' || name[i][j] == 'G' || name[i][j] == 'J' || name[i][j] == 'Q' || name[i][j] == 'X' || name[i][j] == 'Z')){
                codes[ci][cj++] = '2';
                flag = 2;
            }
            else if(flag != 3 && (name[i][j] == 'D' || name[i][j] == 'T')){
                codes[ci][cj++] = '3';
                flag = 3;
            }
            else if(flag != 4 && (name[i][j] == 'L')){
                codes[ci][cj++] = '4';
                flag = 4;
            }
            else if(flag != 5 && (name[i][j] == 'M' || name[i][j] == 'N')){
                codes[ci][cj++] = '5';
                flag = 5;
            }
            else if(flag != 6 && (name[i][j] == 'R')){
                codes[ci][cj++] = '6';
                flag = 6;
            }
            else if(flag != 7 && (name[i][j] == 'A' || name[i][j] == 'E' || name[i][j] == 'I' || name[i][j] == 'O' || name[i][j] == 'U' || name[i][j] == 'Y' || name[i][j] == 'W' || name[i][j] == 'H')){
                flag = 7;
            }
            j++;
        }
        while(cj <= 3)
            codes[ci][cj++] = '0';
        codes[ci][cj] = '\0';
        i++;ci++;
        flag = 0;
    }
    printf("%9sNAME%21sSOUNDEX CODE\n"," "," ");
    i = 0;
    while(i <= n){
        printf("%9s%s"," ",name[i]);
        int padding = 25 - strlen(name[i]);
        printf("%*s%s\n",padding," ",codes[i]);
        i++;
    }
    printf("%19sEND OF OUTPUT"," ");
    return 0;
}

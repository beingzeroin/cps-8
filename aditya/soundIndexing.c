#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printCode(char*);
int getFlagFromSwitchTable(char);

int main(){
    char ch, name[21];
    int i = 0;
    printf("%9sNAME%21sSOUNDEX CODE\n"," "," ");
    while((ch = getchar()) != EOF){
        if(ch == '\n'){
            name[i] = '\0';
            printCode(name);
            i = 0;
        }
        else
            name[i++] = ch;
    }
    /*if(name[i-1] == '\n')
        name[i-1] = '\0';
    else if(name[i-2] == '\n')
        name[i-2] = '\0';
    else
        name[i] = '\0';*/
    name[i] = '\0';
    printCode(name);
    printf("%19sEND OF OUTPUT"," ");
    return 0;
}

void printCode(char *s){
    char code[5];
    int i = 0, j = 0, curr_flag, prev_flag, padding;
    prev_flag = getFlagFromSwitchTable(s[i]);
    code[j++] = s[i++];
    while(s[i] != '\0' && j < 4){
        curr_flag = getFlagFromSwitchTable(s[i]);
        if((curr_flag != prev_flag) && curr_flag != 0)
            code[j++] = (char)curr_flag + '0';
        prev_flag = curr_flag;
        i++;
    }
    while(j < 4)
        code[j++] = '0';
    code[j] = '\0';
    printf("%9s%s"," ",s);
    padding = 25 - strlen(s);
    printf("%*s%s\n",padding," ",code);
}
int getFlagFromSwitchTable(char ch){
    int flag;
    switch(ch){
            case 'A' : case 'E' :
            case 'I' : case 'O' :
            case 'U' : case 'Y' :
            case 'W' : case 'H' : flag = 0;break;

            case 'B' : case 'P' :
            case 'F' : case 'V' : flag = 1;break;

            case 'C' : case 'S' :
            case 'K' : case 'G' :
            case 'J' : case 'Q' :
            case 'X' : case 'Z' : flag = 2;break;

            case 'D' : case 'T' : flag = 3;break;

            case 'L' : flag = 4;break;

            case 'M' : case 'N' : flag = 5;break;

            case 'R' : flag = 6;break;
    }
    return flag;
}

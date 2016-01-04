#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int friendship[2000][2000];
char names[2000][100];
int idx;

void addName(char name[])
{
    strcpy(names[idx], name);
    idx++;
}
int getIndex(char name[])
{
    return -1;
}
int showMenu()
{
    printf("MENU\n");
    printf("1. Add Friendship\n");
    printf("2. List Friends\n");
    printf("3. Mutual Friends\n");
    printf("4. Path Between Two\n");
    printf("5. Stats\n");
    printf("6. Exit\n\n");

    printf("Enter your Choice: ");
    int ch;
    scanf("%d", &ch);
    return ch;
}
int main()
{

    int choice;
    while(true)
    {
        choice = showMenu();
        switch(choice)
        {

        case 6:
            return 0; // exit(0);
        }
    }


    return 0;
}

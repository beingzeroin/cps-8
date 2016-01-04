#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

bool visited[SIZE][SIZE];
bool pathExists(int matrix[SIZE][SIZE],int,int,int);
void printMatrix(int matrix[SIZE][SIZE],int n);
int end_x, end_y;

int main() {

    int t, matrix[SIZE][SIZE];
    scanf("%d\n", &t);
    while(t--){
        int n;
        scanf("%d\n", &n);
        int i, j, start_x, start_y;
        char ch;
        memset(visited,false,sizeof(visited));
        for(i = 0;i < n;i++){
            for(j = 0;j < n;j++){
                ch = getchar();
                if(ch == ' '){
                    j--;
                    continue;
                }
                if(ch == 'A'){
                    matrix[i][j] = ch;
                    start_x = i;
                    start_y = j;
                }
                else if(ch == 'X'){
                    matrix[i][j] = ch;
                    end_x = i;
                    end_y = j;
                }
                else
                    matrix[i][j] = ch - '0';
            }
            ch = getchar();
        }
        if(pathExists(matrix,n,start_x,start_y))
            printf("True%s", (t == 0)?"":"\n");
        else
            printf("False%s", (t == 0)?"":"\n");
    }
    return 0;
}
bool pathExists(int matrix[SIZE][SIZE],int n,int x,int y){
    visited[x][y] = true;
    if(x == end_x && y == end_y)
        return true;
    if((x-1) >= 0 && matrix[x-1][y] != 1 && !visited[x-1][y]){
        if(pathExists(matrix,n,x-1,y))
            return true;
    }
    if((y+1) < n && matrix[x][y+1] != 1 && !visited[x][y+1]){
        if(pathExists(matrix,n,x,y+1))
            return true;
    }
    if((x+1) < n && matrix[x+1][y] != 1 && !visited[x+1][y]){
        if(pathExists(matrix,n,x+1,y))
            return true;
    }
    if((y-1) >= 0 && matrix[x][y-1] != 1 && !visited[x][y-1]){
        if(pathExists(matrix,n,x,y-1))
            return true;
    }
    visited[x][y] = false;
    return false;
}

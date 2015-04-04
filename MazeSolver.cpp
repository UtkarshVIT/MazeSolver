#include<iostream>
#include<stdio.h>
using namespace std;
int N,X1,Y1,X2,Y2;
bool solveMazeUtility(int maze[100][100], int x, int y, int sol[100][100]);
bool isSafe(int maze[100][100], int x, int y,int sol[100][100])
{
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y]==0)
        return true;
    return false;
}
bool solveMaze(int maze[100][100])
{
    int sol[100][100];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            sol[i][j]=0;
    if(solveMazeUtility(maze, X1, Y1, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
    return true;
}

bool solveMazeUtility(int maze[100][100], int x, int y, int sol[100][100])
{
    if(x == X2 && y == Y2)
    {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y,sol) == true)
    {
        sol[x][y] = 1;
        if (solveMazeUtility(maze, x+1, y, sol) == true)
            return true;
        if (solveMazeUtility(maze, x, y+1, sol) == true)
            return true;
        if (solveMazeUtility(maze, x-1, y, sol) == true)
            return true;
        if (solveMazeUtility(maze, x, y-1, sol) == true)
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}
int main()
{
    int maze[100][100];
    char inp;
    cout<<"Enter the size of maze(NxN) :";
    cin>>N;
    cout<<"Enter the maze :"<<endl;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            {
                cin>>inp;
                if(inp=='0')
                    maze[i][j]=0;
                else if(inp=='1')
                    maze[i][j]=1;
                else if(inp=='m')
                {
                    maze[i][j]=1;
                    X1=i;
                    Y1=j;}
                else if(inp=='e')
                {
                    maze[i][j]=1;
                    X2=i;
                    Y2=j;}}
    solveMaze(maze);
    getchar();
    return 0;}

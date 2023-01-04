/*
    Problem Statement: Rat in maze backtracking solution
*/ 
#include<iostream>
#include<vector>
using namespace std;

// no. of rows and no. of column
int N=4,M=4 ;


bool sol[4][4];

bool solveMaze(vector<vector<int>>maze){
    int currRow=0,currCol=0;
    if(solveMazeRec(maze,currRow,currCol)==false){
        return false ;
    }
    else{
        //todo print solution matriz
        return true ;
    }
}

bool isSafe(vector<vector<int>>maze,int currRow,int currCol){
    return(currRow<N&&currCol<N&&maze[currRow][currCol]==1) ;

    
}


bool solveMazeRec(vector<vector<int>>maze,int currRow,int currCol){
    if(currRow==N-1&&currCol==N-1){
        sol[currRow][currCol] = 1;
        return true ;
    }
    if(isSafe(maze,currRow,currCol)){
        sol[currRow][currCol] = 1;
        if(solveMazeRec(maze,currRow+1,currCol)==true) return true ;
        else if(solveMazeRec(maze,currRow,currCol+1)) return true;
        sol[currRow][currCol] = 0 ;
    }
    return false ;
}

int main(){
      vector<vector<int>>maze{
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,1}
    };
    int currRow=0,currCol=0;
    cout<<solveMaze(maze);
    return 0 ;
}
/*
    Problem Statement: Rat in maze
*/ 

#include<iostream>
#include<vector>
using namespace std;
int n=3,m=3;

void ratInMaze(vector<vector<int>>maze,int currRow,int currCol){
    if(currRow==n-1&&currCol==m-1){
        cout<<"yes we are finally out of rat race "<<endl;
        return ;
    }
    // first check to right, that is currCol+1
    if(currCol<m-1&&maze[currRow][currCol+1]==1){
        ratInMaze(maze,currRow,currCol+1);
        cout<<currRow<<" "<<currCol<<endl ;
    }
    
    // then check to bottom,that is currRow+1
    
    if(currRow<n-1&&maze[currRow+1][currCol]==1){
        ratInMaze(maze,currRow+1,currCol);
        cout<<currRow<<" "<<currCol<<endl;
    }
}

int main(){

   vector<vector<int>>maze{
        {1,0,0},
        {0,1,0},
        {1,1,1}
    };
//   vector<vector<int>>maze{
//         {1,1,0},
//         {1,0,0},
//         {1,1,1}
//     };
        
//   vector<vector<int>>maze{
//         {1,0,0,0},
//         {1,1,0,1},
//         {0,1,0,0},
//         {1,1,1,1}
//     };
    int currRow=0,currCol=0;
    ratInMaze(maze,currRow,currCol);
    
    return 0 ;
}
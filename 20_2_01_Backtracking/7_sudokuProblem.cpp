/*
    Problem Statment: Sudoko Problem
*/ 
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
 
//  global variable

int N = 9 ;

int mat[9][9]={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
// int mat[4][4]={
//     {1,0,3,0},
//     {0,0,2,1},
//     {0,1,0,2},
//     {2,4,0,0},
// };

void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row,int col,int num){

    int grid = sqrt(N);

    // check in respective row
    for (int i = 0; i < N; i++)
    {
        if(mat[row][i]==num){
            return false;
        }
    }
    // check in respective column
    for (int i = 0; i < N; i++)
    {
        if(mat[i][col]==num){
            return false ;
        }
    }
    // checking into grid
    // todo

    int startRow = row - row % grid,startCol = col - col % grid;
   
    for (int i = 0; i < grid; i++)
        for (int j = 0; j < grid; j++)
            if (mat[i + startRow][j +
                            startCol] == num)
                return false;
 
    return true;
}

// bool solve(){
//     for(int i=0;i<N;i++){
//         for(int j=0;j<N;j++){
//             if(mat[i][j]==0){
//                 for(int k=1;k<=N;k++){
//                     if(isSafe(i,j,k)){
//                         mat[i][j] = k;
//                         if(solve()){
//                             return true;
//                         }
//                         mat[i][j]=0;
//                     }
                   
//                 }
//                 return false ;
//             }
//         }   
//     }
//     print();
//     return false ;
// }

// solve function with more redablity and optimisation

bool solve(){
    int i,j ;
    bool flag = false ;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mat[i][j]==0){
                flag = true ;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    if(i==N&&j==N){
        return true;
    }

    for(int n=1;n<=N;n++){
        if(isSafe(i,j,n)){
            mat[i][j]=n;
            if(solve()){
                return true;
            }
            mat[i][j]=0;
        }
    }
    return false ;

}
    

int main(){
    cout<<solve()<<endl;
    print();
    return 0;
}
/*
    Problem Statement: N queen problem with another appraoch
    Input: 4
    Output:Yes
*/ 
#include<iostream>
using namespace std;

// global board variable
int N=4;
bool board[4][4];

// is safe 

bool isSafe(int row,int col){
    // checking in same row and different col
    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    // checking for queens top left diagonally
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]){
            return false ;
        }
    }
    // checking for queens bottom left diagonally
    for(int i=row,j=col;i<N&&j>=0;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}


bool solveRec(int col){
    if(col==N) return true;
    for(int i=0;i<N;i++){
        if(isSafe(i,col)){
            board[i][col] = true ;
            if(solveRec(col+1)){
                return true ;
            }
            board[i][col] = false;
        }
    }
    return false ;
}

void printBoard(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solve(){
    if(solveRec(0)){
        printBoard();
        return true;
    }
    return false;
}

int main(){
    cout<<solve()<<endl;
    return 0 ;
}


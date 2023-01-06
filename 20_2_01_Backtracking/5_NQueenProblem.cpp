/*
    Problem Statement: There is N*N board, such that placing N Queens on board, and no queen attack each other.

    Approach:
    1)We generate string of n-1 size, such that if N=4, string would look ike "0123".
    2) Now we take all permutation of string and for each permutation we check that weather queen is placed such that in matrix
    that they won't attack each other.
    3) We check for all path in which queen move, and see that is their any queen in that path, If not we return true if all queens are stable 
    and do not attack each other.
    Otherwise return false. 

    Input: N=3
    Output:false

    Input: N=4
    Output:True
*/ 

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
// this function to generate string on basis of n size board
string generate_string(int n){
     string str = "";
    for(int i=0;i<n;i++){
        stringstream ss ;
        ss<<i ;
        string s;
        ss>>s ; 
        str+=s ;
    }
    return str ;
}

void printVector(vector<vector<int>>v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" " ;
        }
        cout<<endl;
    }
}


bool check(vector<vector<int>>v,int row,int col)
{
      // checking top left in diagonal way
      int i=row,j=col ;
      int n = v.size() ;
      while (i>0&&j>0)
      {
        i--,j--;
        if(v[i][j]==1){
            return false ;
        }
      }
      
      // checking top right in diagonal way
      i =row,j = col;
      while (i!=0&&j<n-1)
      {
        i--,j++;
        if(v[i][j]==1) return false ;
      }
    
      // checking bottom left in diagonal way
       i =row,j = col;
      while (i<n-1&&j>0)
      {
        i++,j--;
        if(v[i][j]==1) return false;
      }
      // checking bottom  right  in diagonal way
         i =row,j = col;
      while (i!=n-1&&j<n-1)
      {
        i++,j++ ;
        if(v[i][j]==1) return false;
      }

         // checing vertically top of co-ordinate
        i=row,j=col ;
        while (i>0)
        {
            i--;
            if(v[i][j]==1) return false;
        }
    // checking vertically bottom of co-ordinate

    i=row,j=col;
    while (i<n-1)
    {
        i++;
        if(v[i][j]==1) return false;
    }
    
    // cout<<row<<" "<<col<<endl;
    
    return true;    
}

// function to see that, weathe given permutation is such that queen don't attack each other

bool isSafe(string str,int n){
    // we declare n*n matrix with default value as 0 ;
    vector<vector<int>>v(n,vector<int>(n,0)) ;
    //  each value of string represent column with respective row

    for(int i=0;i<n;i++){
        char c =str[i];
        int row = int(c-'0') ;
       v[row][i] = 1;
    }
   

    // todo check the given vector weather queens are stable of not

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1){
                if(check(v,i,j)==false) return false ;
                break ;
            }
        }
    }
    return true;
}
// now let's generate all permutation in which N queen could be placed in each column of N*N board

void permutate(string str,int l,int r){
    if(l==r){
    if(isSafe(str,r+1)) {
        cout<<str<<" for this arrangment, queen wont attack in the board "<<endl;
    }
    // isSafe(str,r+1);
      return ;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(str[l],str[i]);
            permutate(str,l+1,r);
            swap(str[l],str[i]);
        }
    }
}

int main(){
    // this generate string
    int n = 5;
    string str = generate_string(n) ;
    int l = 0,r = str.size()-1 ;
    permutate(str,l,r);
    return 0;
}
 
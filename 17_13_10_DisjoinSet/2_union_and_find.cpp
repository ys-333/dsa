/*
    Problem Statement: Union and Find Operation.
    We will use this to solve make friends and areFriends problem

*/ 
#include<iostream>
using namespace std;
class Friend{
    int n ;
    int *parent ;
    public:
    Friend(int n);
    int find(int x) ;
    void Union(int x,int y) ;
    void makeFriends(int x,int y) ;
    bool areFriends(int x,int y) ;
} ;

Friend::Friend(int n){
    this->n =n ;
    parent =new int[n] ;
    for(int i=0;i<n;i++){
        parent[i] = i ;
    }
}
int Friend::find(int x){
    if(parent[x]==x){
        return x; 
    }
    return find(parent[x]) ;
}
void Friend::Union(int x,int y){
    int x_rep = find(x) ;
    int y_rep = find(y) ;
    if(x_rep==y_rep)return ;
    parent[y_rep] = x_rep ;
}
void Friend::makeFriends(int x,int y){
    Union(x,y) ;
}
bool Friend::areFriends(int x,int y){
    if(find(x)==find(y)){
        return true ;
    }
    return false ;
}

int main(){
 Friend f(5) ;
 f.makeFriends(0,1) ;
 f.makeFriends(1,3) ;
 f.makeFriends(1,2) ;
 cout<<f.areFriends(0,4)<<" " ;
 cout<<f.areFriends(0,3)<<" " ;
 cout<<f.areFriends(0,2)<<" " ;
 cout<<f.areFriends(1,2)<<" " ;
}
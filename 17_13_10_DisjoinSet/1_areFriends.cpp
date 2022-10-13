/*
    Problem Statement: Disjoint Data Structure


    // To find that weather two vertect are direct or mutual friend of each other
    
    Input 1:
     int V=5 ;
    vector<int>adj[V] ;
    makeFriends(adj,0,1) ;
    makeFriends(adj,1,3) ;
    makeFriends(adj,1,2) ;
    
    cout<<areFriends(adj,0,4)<<endl ;
    cout<<areFriends(adj,0,3)<<endl ;
    cout<<areFriends(adj,0,2)<<endl ;
    cout<<areFriends(adj,1,2)<<endl ;
    
    
    Output: 0 1 1 1 
    
*/ 
/*
    Approach: 
    We use dfs approach and used adjacency list to reprsent the vertex.
    We use undirected graph as the friend can be mutal

*/ 
#include <iostream>
#include <vector>
using namespace std;
void makeFriends(vector<int>adj[],int u,int v){
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}
bool areFriends(vector<int>adj[],vector<bool>&visited,int u,int v){
    visited[u] = true ;
    for(int x:adj[u]){
        if(x==v){
            return true ;
        }
        // return areFriends(adj,x,v) ;
        else if(visited[x]==false&&areFriends(adj,visited,x,v)){
            return true;
        }
    }
    return false ;
        
       
}
void setFalse(vector<bool>&visited){
    for(int i=0;i<visited.size();i++){
        visited[i] = false ;
    }
}
int main() {
    int V=5 ;
    vector<int>adj[V] ;
    vector<bool>visited(V,false);
    makeFriends(adj,0,1) ;
    makeFriends(adj,1,3) ;
    makeFriends(adj,1,2) ;
    setFalse(visited) ;
    cout<<areFriends(adj,visited,0,4)<<endl ;
    setFalse(visited) ;
    cout<<areFriends(adj,visited,0,3)<<endl ;
    setFalse(visited) ;
    cout<<areFriends(adj,visited,0,2)<<endl ;
    setFalse(visited) ;
    cout<<areFriends(adj,visited,1,2)<<endl ;
    
    // int V=5 ;
    // vector<int>adj[V] ;
    // vector<bool>visited(V,false);
    // makeFriends(adj,2,3);
    // makeFriends(adj,0,2);
    // setFalse(visited) ;
    // cout<<areFriends(adj,visited,0,3)<<" " ;
    // setFalse(visited) ;
    // cout<<areFriends(adj,visited,0,4)<<" " ;
    // makeFriends(adj,3,4) ;
    // setFalse(visited) ;
    // cout<<areFriends(adj,visited,0,4)<<" " ;
    
    // makeFriends(adj,1,4) ;
    // setFalse(visited) ;
    // cout<<areFriends(adj,visited,0,1)<<" " ;
    
    
    // makeFriends(adj,3,4) ;
    return 0;
}
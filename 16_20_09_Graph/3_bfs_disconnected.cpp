/*
    Problem Statement: This Graph is disconnected and we
    have to print the bfs traversal.

    Input:

    addEdge(adj,0,1) ;
    addEdge(adj,0,2) ;
    addEdge(adj,1,3) ;
    addEdge(adj,2,3) ;
    addEdge(adj,4,5) ;
    addEdge(adj,4,6) ;
    addEdge(adj,5,6) ;

    Output:

    0 1 2 3 4 5 6 
*/ 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}

void printGraph(vector<int>adj[],int V){
    for(int i=0;i<V;i++){
     
        for(int x:adj[i]){
            cout<<x<<" " ;
        }
        cout<<endl ;
    }
}

// breadth first search

void bfs(vector<int>adj[],bool visited[],int s){
  
    queue<int>q ;
    q.push(s) ;
    visited[s] = true ;

    while (q.empty()==false)
    {
        int u = q.front() ;
        q.pop() ;
        cout<<u<<" " ;
        for(int x:adj[u]){
            if(visited[x]==false){
                visited[x]=true ;
                q.push(x) ;
            }
        }
    }
}

void bfsDisConnected(vector<int>adj[],int V){
    bool visited[V] ;
    for(int i=0;i<V;i++){
        visited[i] = false ;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            bfs(adj,visited,i) ;
        }
    }
}

int  main(){
   int V=7 ;
   vector<int>adj[V];
    addEdge(adj,0,1) ;
    addEdge(adj,0,2) ;
    addEdge(adj,1,3) ;
    addEdge(adj,2,3) ;
    addEdge(adj,4,5) ;
    addEdge(adj,4,6) ;
    addEdge(adj,5,6) ;
  bfsDisConnected(adj,V);
   cout<<endl;
   printGraph(adj,V);
}
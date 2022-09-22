/*
    Problem Statement:

    Input 1:
    addEdge(adj,0,1) ;
    addEdge(adj,0,2) ;
    addEdge(adj,1,3) ;
    addEdge(adj,1,2) ;
    addEdge(adj,2,3) ;
    addEdge(adj,2,4) ;
    addEdge(adj,3,4) ;

    Output:

    0 1 2 3 4

    Input 2:

    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);

    Output:

    0 4 1 3 2

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



void bfs(vector<int>adj[],int V,int s){
    bool visited[V] ;
    queue<int>q ;
    q.push(s) ;

    for(int i=0;i<V;i++){
        visited[i] = false;
    }
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
    


int  main(){
    int V = 5 ;
    vector<int>adj[V] ;
    
    vector<int>adj[V] ;
    addEdge(adj,0,1) ;
    addEdge(adj,0,2) ;
    addEdge(adj,1,2) ;
    addEdge(adj,1,3) ;
    printGraph(adj,V) ;
    cout<<endl ;
    bfs(adj,V,0) ;
}
   
     
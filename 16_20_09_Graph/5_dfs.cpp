/*
    Depth First Search

    Input:
    int V=7 ;
    vector<int>adj[V] ;
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);

    Output:
        0 1 2 3 4 5 6
*/ 
#include<iostream>
#include<vector>
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

void dfsRec(vector<int>adj[],int s,bool visited[]){
    visited[s] = true ;
    cout<<s<< " " ;
    for(int x:adj[s]){
        if(visited[x]==false){
            dfsRec(adj,x,visited) ;
        }
    }
}


void dfs(vector<int>adj[],int V){
    bool visited[V] = {false} ;

    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfsRec(adj,i,visited) ;
        }
    }
}

int main(){
    int V=6 ;
    vector<int>adj[V] ;
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    // addEdge(adj,5,6);
    printGraph(adj,V) ;
    dfs(adj,V) ;
    return 0 ;
}
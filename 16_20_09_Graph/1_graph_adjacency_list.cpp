#include<iostream>
#include<vector>
using namespace std;

// Graph representation using Adjacency List

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

int main(){
    int V = 4 ;
    vector<int>adj[V] ;
    addEdge(adj,0,1) ;
    addEdge(adj,0,2) ;
    addEdge(adj,1,2) ;
    addEdge(adj,1,3) ;
    printGraph(adj,V) ;
    return 0 ;
}

/*
    Graph representation using Adjacency Matrix


    
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int  V = 4 ;
    int E = 6 ;
    int arr[V][V] ={0};
    for(int i=0;i<E;i++){
        int u,v ;
        cin>>u>>v;
        arr[u][v] = 1 ;
        arr[v][u] = 1 ;
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<arr[i][j]<<" " ;
        }
        cout<<endl ;
    }
}
 
    
*/ 
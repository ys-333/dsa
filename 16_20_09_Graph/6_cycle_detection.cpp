/*
    Problem statement: Cycle detection in undirected Graph.

    Input 1:

        int V = 4 ;
        vector<int>adj[V] ;
        addEdge(adj,0,1) ;
        addEdge(adj,1,2) ;
        addEdge(adj,1,3) ;
        addEdge(adj,2,3) ;

    Output:
        Yes
    
    Input 2:
        addEdge(adj,0,1) ;
        addEdge(adj,1,2) ;
        addEdge(adj,1,3) ;
        addEdge(adj,2,3) ;
        addEdge(adj,2,4) ;
        addEdge(adj,4,5) ;

    Output:
        Yes
    
    Input 3:
        addEdge(adj,0,1) ;
        addEdge(adj,1,2) ;
        addEdge(adj,1,3) ;
        addEdge(adj,3,4) ;
    
    Output:
        No

*/ 

#include <iostream>
#include <vector>
#include <queue>
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
        cout<<endl;
    }
    cout<<endl ;
}


/**************Cycle Detection using DFS**************************/ 

bool dfsRec(vector<int>adj[],int s,bool visited[],int parent){
    visited[s] =true ;
    cout<<s<<" " ;
    for(int x:adj[s]){
        if(visited[x]==false){
            parent = s ;
    
            if(dfsRec(adj,x,visited,parent)==true){
                return true ;
            } ;
        }
        else{
            if(x!=parent){
                return true ;
            }
        }
    }
    return false ;
}
    

bool dfs(vector<int>adj[],int V){
    bool visited[V] = {false} ;
    
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            return dfsRec(adj,i,visited,-1) ;
            // visited[i] = true ; 
            // if(dfsRec(adj,i,visited,-1)==true){
            //   cout<<"it has circle"<<endl ;
            //   return ;
            // }
        }
    }
}

/******************************************************/ 


bool cycleDetectionUsingBfs(vector<int>adj[],int s,int V){
    bool visited[V] = {false} ;
    queue<int>q ;
    q.push(s) ;
    visited[s] = true ;
    int parent[V] ;

    for(int i=0;i<V;i++){
        parent[i] = -1 ;
    }

    while (q.empty()==false)
    {
        s = q.front() ;
        q.pop() ;
        for(int x:adj[s]){
            if(visited[x]==false){
                parent[x] = s ;
                visited[x] = true ;
                q.push(x) ;     
            }
            else{
                if(parent[s]==parent[x]){
                    return true ;
                }
            }
        }
    }
    return false ;
}

int main() {
    int V = 6 ;
    vector<int>adj[V] ;
    addEdge(adj,0,1) ;
    addEdge(adj,1,2) ;
    addEdge(adj,1,3) ;
    addEdge(adj,3,4) ;
    
    printGraph(adj,V) ;
    cout<<dfs(adj,V) ;
    return 0;
}

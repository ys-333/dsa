/*
    ? Dijkstra’s shortest path algorithm using Heap in O(E logV):
*/ 
#include<iostream>
#include<queue>
#include<utility>
#include<climits>
#include<vector>
using namespace std;

typedef pair<int,int> iPair ;

class Graph{
    int V ;
    vector<iPair>*adj; 
    public:
    Graph(int V) ;
    void addEdge(int u,int v,int w) ;
    void print() ;
    void shortest_path(int s) ;
};

Graph::Graph(int v){
    V = v ;
    adj = new vector<iPair>[V] ;
}
void Graph::addEdge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w)) ;
    adj[v].push_back(make_pair(u,w)) ;
}
void Graph::print(){
    for(int i=0;i<V;i++){
        for(iPair x:adj[i]){
            cout<<x.first<<" " ;
        }
        cout<<endl ;
    }
}
void Graph::shortest_path(int s){
    vector<int>dist(V,INT_MAX) ;
    dist[s] = 0 ;
    priority_queue<iPair,vector<iPair>,greater<iPair>>q ;
    q.push(make_pair(0,s)) ;
    while(!q.empty()){
        iPair x = q.top() ;
        q.pop() ;
        int u = x.second ;

        for(iPair x:adj[u]){
            int v = x.first ;
            int w = x.second ;
            if(dist[v]>w+dist[u]){
                dist[v] = w+dist[u] ;
                q.push(make_pair(dist[v],v)) ;
            }
        } 
    }

    // printing the shortest distance from the source vertex.
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<< " " ;
    }
}

int main(){
    Graph g(4) ;
    g.addEdge(0,1,4) ;
    g.addEdge(0,2,5) ;
    g.addEdge(1,2,3) ;
    g.addEdge(1,3,10) ;
    g.addEdge(2,3,2) ;
    g.print() ;
    cout<<endl ;
    g.shortest_path(0) ;
}
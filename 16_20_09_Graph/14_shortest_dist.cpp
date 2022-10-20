/*
    Problem Statement: //? Shortest path using prims algorithm
*/ 
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
    // helper function for shortest_path
    int min_index(vector<int>dist,vector<bool>sptSet) ;
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

int Graph::min_index(vector<int>dist,vector<bool>mstSet){
    int minNumber = INT_MAX, minIndex = 0 ;
    for(int i=0;i<V;i++){
        if(!mstSet[i]&&dist[i]<minNumber){
            minNumber = dist[i] ;
            minIndex = i;
        }
    }
    return minIndex ;
}

void Graph::shortest_path(int s){
   vector<int>dist(V,INT_MAX);
   vector<bool>sptSet(V,false) ;
   dist[s] = 0 ;
   for(int i=0;i<V;i++){
        int u = min_index(dist,sptSet) ;
        sptSet[u] = true ;
        for(iPair x:adj[u]){
            if(sptSet[x.first]==false&&dist[x.first]>dist[u]+x.second){
                dist[x.first] = dist[u]+x.second ;
            }
        }
   }
   for(int i=0;i<V;i++){
    cout<<dist[i]<<" " ;
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
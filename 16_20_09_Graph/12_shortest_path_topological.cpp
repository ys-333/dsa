/*
    Problem Statement: Shortest path using topological sort
*/ 
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
class Node{
    int w,v; 
    public:
    Node(int v,int w){
        this->v = v; 
        this->w = w; 
    }
    int getV(){
        return v ;
    }
    int getW(){
        return w ;
    }
}; 
class Graph{
    int V ;
    vector<Node>*adj ;
    public:
    Graph(int V) ;
    void addEdge(int u,int v,int w) ;
    void printGraph() ;
    void shortest_path(int source) ;
} ;
Graph::Graph(int V){
    this->V = V ;
    adj = new vector<Node>[V];
}
void Graph::addEdge(int u,int v,int w){
    Node temp(v,w) ;
    adj[u].push_back(temp) ;
}
void Graph::printGraph(){
    for(int i=0;i<V;i++){
        for(Node x:adj[i]){
            cout<<x.getV()<<" " ;
        }
        cout<<endl ;
    }
}
void Graph::shortest_path(int source){
    vector<int>dist(V,INT_MAX);
    dist[source] = 0 ;
    vector<int>indegree(V,0) ;
    for(int i=source;i<V;i++){
        for(Node x:adj[i]){
            indegree[x.getV()]++ ;
        }
    }
    queue<int>q ;
    for(int i=source;i<V;i++){
        if(indegree[i]==0){
            q.push(i) ;
        }
    }


    // now loop

    while(q.empty()==false){
        int s = q.front() ;
        q.pop() ;
        for(Node x:adj[s]){
            indegree[x.getV()]-- ;
            int curr_dist = dist[s]+x.getW() ;
            dist[x.getV()] = min(dist[x.getV()],curr_dist) ;
            if(indegree[x.getV()]==0){
                q.push(x.getV()) ;
            }
        }
    }
    for(int i=source;i<V;i++){
        cout<<dist[i]<<" " ;
    }
}
int main(){
    Graph g(4) ;
    g.addEdge(0,1,5) ;
    g.addEdge(0,2,10) ;
    g.addEdge(1,1,5) ;
    g.addEdge(0,1,5) ;
    g.addEdge(0,1,5) ;
}
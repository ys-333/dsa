/*
    Problem Statement: Shortest path in Directed acylic graph using DFS.
    
    
    Input 1:
    
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);
    g.shortest_path(0) ;
    
    Output: 0 2 3 6 1 5
    
    Input 2:
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(1, 3, 2);
    g.shortest_path(1) ;

    Output: INF 0 3 2
    
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Node{
    int v; 
    int w ;
    public:
    Node(int v,int w){
        this->v =v;
        this->w =w;
    }
    int getV(){
        return v ;
    }
    int getW(){
        return w ;
    }
};

class Graph{
    int V;
    vector<Node>*adj;
    public:
    Graph(int V) ;
    void addEdge(int u,int v,int weight) ;
    void printGraph() ;
    void shortest_path(int s) ;
    void dfs(Node s,vector<int>&dist,int parent) ;
    
};
Graph::Graph(int V){
    this->V =V ;
    adj = new vector<Node>[V];
}
void Graph::addEdge(int u,int v,int weight){
    Node temp(v,weight) ;
    adj[u].push_back(temp) ;
}
void Graph::printGraph(){
    for(int i=0;i<V;i++){
        for(auto x:adj[i]){
            cout<<x.getV()<<" ";
        }
        cout<<endl ;
    }
}
void Graph::shortest_path(int s){
    vector<int>dist(V,INT_MAX) ;
    Node source(s,0) ;
    dist[s] = 0 ;
    int parent = -1 ;
    dfs(source,dist,parent) ;
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" " ;
    }  
}


void Graph::dfs(Node s,vector<int>&dist,int parent){
    if(parent!=-1){
        int curr_dist = parent+s.getW() ;
        dist[s.getV()] = min(dist[s.getV()],curr_dist) ; 
    }
    for(Node x:adj[s.getV()]){
        dfs(x,dist,dist[s.getV()]) ;
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(1, 3, 2);
    g.shortest_path(1) ;
    // g.printGraph();
    // g.printGraph() ;
    // g.shortest_path(temp, v, 0);
    // print(v);
}
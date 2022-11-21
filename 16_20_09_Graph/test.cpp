#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
// directed and weighted graph
// u---->v w

class Node{
    int v,w ;
    public:
    Node(int v,int w){
        this->v = v ;
        this->w = w ;
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
    vector<Node>*adj ;
    public:
    Graph(int V) ;
    void addEdge(int u,int v,int w);
    void shortest_path(int s) ;
    // ! to add dfs logic
    void topo_sort(vector<int>&dist,int s) ; 
};

Graph::Graph(int V){
    this->V=V ;
    adj = new vector<Node>[V] ;
}
void Graph::addEdge(int u,int v,int w){
    Node temp(v,w) ;
    adj[u].push_back(temp);
}
void Graph::shortest_path(int s){
    // will get the source vertex
    // need to print shortest distance from the source
    vector<int>dist(V,INT_MAX) ;
    dist[s] = 0 ;
    topo_sort(dist,s) ;
}

void Graph::topo_sort(vector<int>&dist,int s){
    // indegree calculation
    vector<int>indegree(V,0) ;
    for(int i=s;i<V;i++){
        for(auto x:adj[i]){
            indegree[x.getV()]++ ;
        }
    }
    // push into queue into indegree
    queue<int>q ;
    for(int i=s;i<V;i++){
        q.push(i);
    }
    // to calculate the shortest distance

    while(q.empty()==false){
        s = q.front() ;
        q.pop() ;
        for(auto x:adj[s]){
            int v = x.getV() ;
            int w = x.getW() ;
            indegree[v]-- ;
            if(indegree[v]==0){
                q.push(v) ;
            }
            dist[v] = min(dist[v],w+dist[s]) ;
        }
    }
    // print the content of the dist vector
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" " ;
    }

}

int main(){
     Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);
    g.shortest_path(0) ;
}

/*
      vector<int>indegree(V,0) ;
//    indegree calculation
   for(int i=s;i<V;i++){
        for(auto x:adj[i]){
            indegree[x.getV()]++ ;
        }
   }
   queue<int>q ;
   for(int i=s;i<V;i++){
        if(indegree[i]==0){
            q.push(i) ;
        }
   }
   while(q.empty()==false){
    s = q.front() ;
    q.pop();
    for(auto x:adj[s]){
        indegree[x.getV()]-- ;
        if(indegree[x.getV()==0]){
            q.push(x.getV()) ;
        }
        if(dist[x.getV()]>dist[s]+x.getW()){
            dist[x.getV()] = dist[s]+x.getW();
        }
    }
*/ 
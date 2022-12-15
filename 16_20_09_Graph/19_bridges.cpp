/*
        Example:

        0----2----3----4
        |  /         \ |
        |/            \|
        1              5  

    In above graph, edge (2,3) is an bridges, that means if we remove that edge, our
    Graph split into two or more components.
*/ 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Graph
{
private:
    int V;
    vector<int>*adj;
    /* data */
public:
    Graph(int v);
    void addEdge(int u,int v);
    void print();
    void bridges();
    void dfs(int u,int parent,vector<int>&disc,vector<int>&low,vector<bool>&visited,int &time);
};

Graph::Graph(int v)
{   
    V = v;
    adj = new vector<int>[V];
}
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::print(){
    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void Graph::bridges(){
    vector<int>disc(V,0);
    vector<int>low(V,INT_MAX);
    vector<bool>visited(V,false);
    int parent = -1;
    int time =0;
    
    // this loop ensure that we get bridges even if graph is disconnected
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfs(i,parent,disc,low,visited,time);
        }
    }

}

void Graph::dfs(int u,int parent,vector<int>&disc,vector<int>&low,vector<bool>&visited,int &time){
    visited[u] = true ;
   disc[u] = ++time;
   low[u] = time ;

    for(int v:adj[u]){
        if(visited[v]==false){
            dfs(v,u,disc,low,visited,time);

            // this ensure that if child i.e v has any backedges to ancestor of u, so in that case we update the low value of u
            low[u] = min(low[u],low[v]);

            if(parent!=-1&&low[v]>disc[u]){
                cout<<"edge from "<<u<<" to "<<v<<" is an bridge in current graph "<<endl;
            }

        }
        else if(v!=parent){
            low[u] = min(low[u],disc[v]);
        }
    }
}

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.bridges();
    return 0;
}

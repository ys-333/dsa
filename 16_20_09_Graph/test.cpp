/*PRIMS ALGORITHM*/ 

#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
typedef pair<int,int>edge ;

class Graph{
    int V;
    vector<edge>*adj;
    public:
    Graph(int v){
        V=v;
        adj = new vector<edge>[V];
    }
    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    void shortest_path(int s){
       vector<int>dist(V,INT_MAX);
       dist[s] = 0 ;
       priority_queue<edge,vector<edge>,greater<edge>>pq ;
       pq.push(make_pair(dist[s],s));
       while (pq.empty()==false)
       {
            edge x= pq.top();
            pq.pop();
            int w = x.first ;
            int u = x.second;
            for(edge v:adj[u]){
                if(dist[v.first]>dist[u]+v.second){
                    dist[v.first] = dist[u]+v.second ;
                    pq.push(make_pair(dist[v.first],v.first));
                }
            }
       }
       
       for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
       }
    }
               
                
        
    void print(vector<int>dist){
        for(int i=0;i<V;i++){
            cout<<dist[i]<<" ";
        }
    }
};
int main(){
     Graph g(4) ;
    g.addEdge(0,1,4) ;
    g.addEdge(0,2,5) ;
    g.addEdge(1,2,3) ;
    g.addEdge(1,3,10) ;
    g.addEdge(2,3,2) ;
    g.shortest_path(0) ;
}
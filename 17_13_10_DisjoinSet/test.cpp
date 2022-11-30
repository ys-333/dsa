#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
    int w,s,d;
    public:
    Edge(int w,int s,int d){
        this->w = w ;
        this->s = s ;
        this->d = d ;
    }
    int getW(){
        return w;
    }
    int getS(){
        return s;
    }
    int getD(){
        return d; 
    }
};
class Disjoint{
    int *parent,*rank,n;
    public:
    Disjoint(int n){
        this->n = n ;
        parent = new int[n];
        rank = new int[n];
        init() ;
    }
    void init(){
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            rank[i]=0;
        }
    }
    // path compression method
    int find(int x){
        if(parent[x]==x){
            return x ;
        }
        parent[x] = find(parent[x]) ;
        return parent[x] ;
    }
    // union by rank
    void Union(int x,int y){
        int x_rep = find(x) ;
        int y_rep = find(y) ;
        if(x_rep==y_rep){
            return ;
        }
        if(rank[x_rep]<rank[y_rep]){
            parent[x_rep] = y_rep ;
        }
        else if(rank[y_rep]<rank[x_rep]){
            parent[y_rep] = x_rep ;
        }
        else{
            parent[y_rep] = x_rep ;
            rank[x_rep]++ ;
        }
    }
};

class Graph{
    int V;
    vector<Edge>adj ;
    public:
    Graph(int V){
        this->V =V ;
    }
    void addEdge(int w,int s,int d){
        Edge temp(w,s,d);
        adj.push_back(temp) ;
    }
    static bool myCmp(Edge e1,Edge e2){
        return e1.getW()<e2.getW() ;
    }
    // kruskal algo to find minimum spanning tree
    int kruskal_mst(){
        Disjoint d(V) ;
        sort(adj.begin(),adj.end(),myCmp) ;
        int res =0 ;
        for(int i=0;adj.size();i++){
            Edge temp = adj[i] ;
            int x = d.find(temp.getS());
            int y = d.find(temp.getD());
            if(x!=y){
                res+=temp.getW();
                d.Union(x,y);
            }

        }

    }
};
    
                


int main(){
  Graph g(5);
  g.addEdge(6,0,1); 
  g.addEdge(5,0,2); 
  g.addEdge(3,1,2); 
  g.addEdge(8,1,3); 
  g.addEdge(7,2,3); 
  g.addEdge(12,2,4); 
  g.addEdge(10,3,4);
  cout<<g.kruskal_mst()<<endl ;
    return 0 ;
}
/*
    ? Approach
    Todo: 1) First sort the Edges of graph in order of weight 
        todo:Take a edge and see that weather it contain cycle or not (Use find operation to see that it contain cycle or not)
        * If not then put into MST i.e call union operation and add it's weight into res.
        ! else don't put into mst array

    ? So we need to use find and union operation

    * Time complexity:
    ? O(Elog(E)+V+mlogV)
    
*/ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//? Disjoint Class
class Disjoint{
    int n ;
    int *parent ,*rank;
    public:
    Disjoint(int n){
        this->n = n ;
        parent = new int[n] ;
        rank = new int[n] ;
        init() ;
    }

    void init(){
        for(int i=0;i<n;i++){
            parent[i] = i ;
        }
        for(int i=0;i<n;i++){
            rank[i] = 0 ;
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return find(parent[x]) ;
    }
    void Union(int x,int y){
        int x_rep = find(x) ;
        int y_rep = find(y) ;
        if(rank[x_rep]>rank[y_rep]){
            parent[y_rep] = x_rep ;
        } 
        else if(rank[x_rep]<rank[y_rep]){
            parent[x_rep] = y_rep ;
        } 
        else{
            parent[y_rep] = x_rep ;
            rank[x_rep]++ ;
        }
    }

   
} ;



//? Class Node

class Edge{
    int source,dest,weight ;
    public:
    Edge(int w ,int s,int d){
        source = s ;
        dest = d ;
        weight =w ;
    }
    int getSource(){
        return source ;
    }
    int getDest(){
        return dest ;
    }
    int getWeight(){
        return weight ;
    }

};


//? Graph Class

class Graph{
    int V ;
    vector<Edge>addE ;
    public:

    Graph(int v){
        V =v ;
    }

    void addEdge(int  weight,int source,int dest){
        Edge temp(weight,source,dest) ;
        addE.push_back(temp);
    }
    
    static bool myCmp(Edge e1,Edge e2){
        return e1.getWeight()<e2.getWeight() ;
    }
   
    int kruskal_mst(){
        Disjoint d(V) ;
        
        sort(addE.begin(),addE.end(),myCmp) ;
        
        int resWeight = 0  ;
        
        for(int i=0,s=0;s<V-1;i++){
            int x = d.find(addE[i].getSource()) ;   
            int y = d.find(addE[i].getDest()) ;   
            if(x!=y){
                resWeight+=addE[i].getWeight() ;
                d.Union(x,y) ;
                s++ ;
            }
        }
        
        
        return resWeight;
    }
};

int main(){
    // Edge arr = {}
    Graph g(5) ;
    g.addEdge(3,1,3) ;
    g.addEdge(4,2,3) ;
    g.addEdge(5,1,2) ;
    g.addEdge(8,0,2) ;
    g.addEdge(10,0,1) ;
    g.addEdge(12,2,4) ;
    g.addEdge(15,3,4) ;
    cout<<g.kruskal_mst()<<endl ;
}
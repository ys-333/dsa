#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Graph{
    int V;
    vector<int>*adj;
    public:
    Graph(int v){
        V = v;
        adj = new vector<int>[V];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print(){
        for(int i=0;i<V;i++){
            for(int x:adj[i]){
                cout<<x<<" ";
            }
        }
    }

    void dfs(int parent,int s,vector<int>&discTime,vector<int>&lowTime,vector<bool>&visited){
        
        visited[s] = true;
        if(parent!=-1){
            discTime[s] = discTime[parent]++;
        }

        for(int x:adj[s]){
            if(visited[x]==false){
                dfs(s,x,discTime,lowTime,visited);
            }
            else{
                if(lowTime[s]>discTime[x]){
                    lowTime[s] = discTime[x];
                }
            }   
        }
        
       
    }

    void printVector(vector<int>v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" " ;
        }
        cout<<endl;
    }

    void articulation_point(){
        vector<bool>visited(V,false);
        vector<int>discTime(V,0);
        vector<int>lowTime(V,INT_MAX);
        int parent = -1;
        int s = 0 ;
        discTime[s] = 1;
        lowTime[s] = 1;
        dfs(parent,s,discTime,lowTime,visited);
        printVector(discTime);
        printVector(lowTime);
    }
};


int main(){
     Graph g(4);
	// g.addEdge( 0, 1);
	// g.addEdge( 0, 3);
	// g.addEdge( 1, 2);
	// g.addEdge( 3, 4);
    // g.print();
    // g.articulation_point() ;
    g.addEdge( 0, 1);
    g.addEdge( 1, 2);
    g.addEdge( 2, 3);
    g.articulation_point();
}
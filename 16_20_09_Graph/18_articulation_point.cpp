/*

*/ 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void print(vector<int>adj[],int V){
    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

class Graph{
    int V;
    vector<int>*adj;
    public:
    Graph(int v){
        V=v;
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
            cout<<endl;
        }
    }

   
    void dfs(int s,vector<bool>&visited){
        visited[s] = true;
        for(int x:adj[s]){
            if(visited[x]==false){
                dfs(x,visited);
            }
        }
    }

    bool connected_comp(){
        vector<bool>visited(V,false);
        int count = 0;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                count++ ;
                dfs(i,visited);
            }
        }
        // since we are also counting the removed vertex
        count = count-1;
        if(count>=2){
            return true ;
        }
        return false ;
    }
      
      

    void adding_edge(vector<int>&backup){
        for(int i=1;i<backup.size();i++){
            adj[backup[0]].push_back(i);
            adj[backup[i]].push_back(backup[0]);
        }
    }
    
     void deleteEdges(int u,int v){
        // cout<<" u "<<u<<" v "<<v<<endl;
        // deleting edge from u to v
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i]==v){
                adj[u].erase(adj[u].begin()+i);
            }
        }
        // deleting edge from v to u
        for(int i=0;i<adj[v].size();i++){
            if(adj[v][i]==u){
                adj[v].erase(adj[v].begin()+i);
            }
        }
    }


    void articulation_point(){
        vector<int>backup ;
        for (int i = 0; i < V; i++)
        {   backup.push_back(i);
            
            // for(int j=0;j<adj[i].size();j++){
            // //   cout<<adj[i][j]<<" ";
            //   backup.push_back(adj[i][j]);
            //   deleteEdges(i,adj[i][j]);
            // }
              
           
            
            for(int x:adj[i]){
                backup.push_back(x);
                // cout<<i<<" "<<x<<endl;
                deleteEdges(i,x);
            }
            // printRow(i);
            bool res=connected_comp();
            if(res){
                cout<<i<<" ";
            }
            adding_edge(backup);
            backup.clear();
        }
        
    }
    void printRow(int i){
        cout<<"row "<<i<<" "<<endl;
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};


int main(){
    int V = 7;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
//   g.addEdge(0,1);
//   g.addEdge(0,2);
//   g.addEdge(0,3);
//   g.addEdge(1,2);
//   g.addEdge(3,4);

    
    // int V=4;
    // Graph g(V);
    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.print();
    g.articulation_point();
}


/*
    Try to find articulation point using indegree method

    void articulation_point(vector<int>adj[],int V){
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            indegree[x]++;
        }
    }
    int res=INT_MIN,v;
    for(int i=0;i<V;i++){
        if(indegree[i]>res){
            res = indegree[i];
            v = i;
        }
    }
    cout<<"The vertex "<<v<<" is articulation point "<<endl;
}
int main

*/
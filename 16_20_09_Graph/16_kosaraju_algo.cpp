/*
    Problem Statement: Print all Strongly connected components using kosaraju algorithm.

    todo: It require two dfs traversal.
    
    !In the first traversal we make dfs traversal and push the adjacent vertex into the stack.
    
    ?Then we reverse the edges of graph.
    

    ?now we make dfs travesal by taking all the vertext from the stack and calling dfs on that vertex.

    Input:
    Graph g(5);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.printConnectedComponent();

    Output:

    0 1 2
    3
    4
*/ 

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector<int>*adj;
    vector<int>*revG;
    public:
    Graph(int v){
        V = v;
        adj = new vector<int>[V];
        revG = new vector<int>[V];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    void print(){
        for(int i=0;i<V;i++){
            for(int x:adj[i]){
                cout<<x<<" ";
            }
        }
        cout<<endl;
    }
    void reverseGraph(){
        for(int i=0;i<V;i++){
            for(int x:adj[i]){
               revG[x].push_back(i);
            }
        }
    }

    void fillOrder(int s,vector<bool>&visited,stack<int>&st){
        visited[s] = true ;

        for(int x:adj[s]){
            if(visited[x]==false){
                fillOrder(x,visited,st);
            }
        }
        st.push(s);
    }

    void dfs(int s,vector<bool>&visited){
        visited[s]=true ;
        cout<<s<<" ";
        for(int x:revG[s]){
            if(visited[x]==false){
                dfs(x,visited);
            }
        }
    }


    void printConnectedComponent(){
        vector<bool>visited(V,false);
        stack<int>st;
        // finding the order of vertices
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                fillOrder(i,visited,st);
            }
        }
        
        for(int i=0;i<V;i++){
            visited[i] = false ;
        }

        // reverse the graph

        reverseGraph();

        // make normal dfs call for all the vertices which are in stack

        while(st.empty()==false){
            int s = st.top();
            st.pop();
            if(visited[s]==false){
                dfs(s,visited);
                cout<<endl;
            }
        }
    }
};
                


int main()
{
    Graph g(5);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.printConnectedComponent();
    return 0 ;
}
    
/*
    Problem Statement: Find strongly connected componentes using tarjan algorithm

    Input 1:
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(2,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.tarjan();
    
    Output:
    4
    3
    2 1 0

    Input 2:
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);
    g.tarjan();

    Ouput:
    1
    4 3 2
    0

    In Input two, it contain cross edge unlike back-edge which we normally see. So instead of using visited boolean array we use stackMember 
    boolean array, which is true for vertex till it's in the stack or recursion call stack, otherwise we make it false after its execution context is over


*/ 




#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#define NIL -1
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
    void tarjan();
    void dfs(int u,int parent,vector<int>&disc,vector<int>&low,vector<bool>&visited,int &time,stack<int>&st);
};

Graph::Graph(int v)
{   
    V = v;
    adj = new vector<int>[V];
}
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}
void Graph::print(){
    for(int i=0;i<V;i++){
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void Graph::tarjan(){
    vector<int>disc(V,NIL);
    vector<int>low(V,NIL);
    vector<bool>stackMember(V,false);
    stack<int>st;
    int parent = -1;
    int time =0;
    
    // this loop ensure that we get bridges even if graph is disconnected
    for(int i=0;i<V;i++){
        if(disc[i]==NIL){
            dfs(i,parent,disc,low,stackMember,time,st);
        }
    }

}

void Graph::dfs(int u,int parent,vector<int>&disc,vector<int>&low,vector<bool>&stackMember,int &time,stack<int>&st){
   stackMember[u] = true ;
   disc[u] = ++time;
   low[u] = time ;
   st.push(u);

    for(int v:adj[u]){
        if(disc[v]==NIL){
            dfs(v,u,disc,low,stackMember,time,st);

            // this ensure that if child i.e v has any backedges to ancestor of u, so in that case we update the low value of u
            low[u] = min(low[u],low[v]);
        }
        else if(v!=parent&&stackMember[v]==true){
            low[u] = min(low[u],disc[v]);
        }
    }
    stackMember[u] = false;
    if(disc[u]==low[u]){
        while (st.top()!=u)
        {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<st.top()<<endl;
        st.pop();
    }
}
        

int main(){
    // Graph g(6);
    // g.addEdge(0,1);
    // g.addEdge(2,0);
    // g.addEdge(1,2);
    // g.addEdge(1,3);
    // g.addEdge(3,4);
    // g.tarjan();
    // this contain cross edge

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);
    // g.print();
    g.tarjan();
    return 0;
}

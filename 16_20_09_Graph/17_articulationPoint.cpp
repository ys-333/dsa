/*
    Problem Statement: To find articulation point or cut-vertex.
    It is that vertex which once remove will split the graph into two or more strongly connected components.

     todo: We can find articulation point using dfs traversal

    ! In DFS tree, a vertex u is an articulation point if one of the following two conditions is true:
        ? 1) u is the root of the DFS tree and it has atleast two children.
        ? 2) u is not the root of the DFS tree and it has a child v such that no vertex in the subtree 
        ? rooted with v has a back edge to one of the ancestors in DFS tree of u.
        ? (low[v]>=disc[u]) that mean vertex v can not reach the ancestor of u, that mean cutting vertex u wil split the 
        ? components into two or more strongly connected components.


        We maintain discovery and low vector.
        discTime = Time required to reach that particular vertex in dfs traversal
        lowTime = at vertex "v" if it has any back edge to  vertex u such that  low[v]>=disc[u], so we can update low[v] = disc[u];  
        
*/ 


#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Graph{
    int V;
    vector<int>*adj;
    public:
    Graph(int v){
        this->V = v;
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
    void dfs(int u,int parent,vector<int>&disc,vector<int>&low,vector<bool>&visited,vector<bool>&isAp,int &time){
        visited[u] = true;
        disc[u]=low[u]= ++time;
        int children = 0 ;
        for(int v:adj[u]){
            if(visited[v]==false){
                children++;
                dfs(v,u,disc,low,visited,isAp,time);

                low[u] = min(low[u],low[v]);

                if(parent!=-1&&low[v]>=disc[u]){
                    isAp[u]= true ;
                }

            }
            else if(v!=parent){
                low[u] = min(low[u],disc[v]);
            }
        }
        
        // to check root has two children 
        if(parent==-1&&children>1){
            isAp[u] =true;
        }
    }
    void articulation_point(){
        // disc,low,isAp,visisted == array
        // parent, source == int
        vector<int>disc(V,0);
        vector<int>low(V,INT_MAX);
        vector<bool>isAp(V,false);
        vector<bool>visited(V,false);
        int parent = -1;
        int time = 0 ;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                cout<<"make the "<<i<<" first call"<<endl;
                dfs(i,parent,disc,low,visited,isAp,time);
            }
        }
        cout<<"hopefully we reach here"<<endl ;
        // print isAp vector
        for(int i=0;i<V;i++){
            if(isAp[i]==true){
                cout<<i<<" ";
            }
        }
    }
};
int main(){
    // Graph g(5);
    // cout << "Articulation points in first graph \n";
	// g.addEdge(1,0);
	// g.addEdge(0,2);
	// g.addEdge(2,1);
	// g.addEdge(0,3);
	// g.addEdge(3,4);
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
	g.articulation_point();
	return 0 ;
}





// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;

// void print(vector<int>adj[],int V){
//     for(int i=0;i<V;i++){
//         for(int x:adj[i]){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
// }

// class Graph{
//     int V;
//     vector<int>*adj;
//     public:
//     Graph(int v){
//         V=v;
//         adj = new vector<int>[V];
//     }

//     void addEdge(int u,int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//     }

//     void print(){
//         for(int i=0;i<V;i++){
//             for(int x:adj[i]){
//                 cout<<x<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     // utility function to built discovery time and low time using dfs traversal
//     /*
//         discTime -->discovery time in dfs traversal
//         low --> from a vertex the lowest discovery time vertex we can access. that is what i called as low time.
//     */ 
//     void utility_articulartionPoint(int s,vector<bool>&visited,vector<int>&discTime,vector<int>&low,int &count,int parent){
//         discTime[s]=++count;
//         visited[s] =true ;
//         for(int x:adj[s]){
//             if(visited[x]==false){
//                 utility_articulartionPoint(x,visited,discTime,low,count,s);
//             }
//             else{
//                 if(low[s]>discTime[x]){
//                     low[s] = discTime[x];
//                 }
//             }
//         }
//         if(parent!=-1){
//             if(low[s]>=discTime[parent]){
//                 cout<<parent<<" ";
//             }
//         }
//     }
//     void articulation_point(){
//         vector<bool>visited(V,false);
//         vector<int>discTime(V,0);
//         vector<int>low(V,INT_MAX);
//         int count =0;
//         low[0]=1;
//         int parent = -1 ;
//         utility_articulartionPoint(0,visited,discTime,low,count,parent);
//         // print discTime and low
//         // for(int i=0;i<V;i++){
//         //     cout<<discTime[i]<<" "<<low[i]<<" "<<endl;
//         // }
//     }
// };


// int main(){
//     int V = 7;
//     Graph g(V);
//     g.addEdge(0, 1);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(1, 3);
//     g.addEdge(1, 4);
//     g.addEdge(1, 6);
//     g.addEdge(3, 5);
//     g.addEdge(4, 5);
//     // g.addEdge( 1, 0);
//     // g.addEdge( 0, 2);
//     // g.addEdge( 2, 1);
//     // g.addEdge( 0, 3);
//     // g.addEdge( 3, 4);

    
//     // int V=4;
//     // Graph g(V);
//     // g.addEdge(0,1);
//     // g.addEdge(0,2);
//     // g.addEdge(1,2);
//     // g.addEdge(2,3);
//     // g.print();
//     g.articulation_point();
// }


// /*
//     Try to find articulation point using indegree method

//     void articulation_point(vector<int>adj[],int V){
//     vector<int>indegree(V,0);
//     for(int i=0;i<V;i++){
//         for(int x:adj[i]){
//             indegree[x]++;
//         }
//     }
//     int res=INT_MIN,v;
//     for(int i=0;i<V;i++){
//         if(indegree[i]>res){
//             res = indegree[i];
//             v = i;
//         }
//     }
//     cout<<"The vertex "<<v<<" is articulation point "<<endl;
// }
// int main

// */
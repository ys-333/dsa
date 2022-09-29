/*
    Problem Statement: Cycle Detection in directed graph
    using Kahn's algorithm(bfs)

    Input 1:
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Input 2:
    int V = 4 ;
    vector<int>adj[V] ;
    addEdge(adj,0,1) ;
    addEdge(adj,1,2) ;
    addEdge(adj,2,3) ;
    addEdge(adj,2,0) ;

    Output: Yes

    Input 2:
    int V = 4 ;
    vector<int>adj[V] ;
    addEdge(adj,0,1) ;
    addEdge(adj,1,2) ;
    addEdge(adj,2,3) ;
    addEdge(adj,0,2) ;

    Output: No

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void bfsRec(vector<int> adj[], vector<int> &indegree, queue<int> q)
{

    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();
        for (int x : adj[front])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
}

// bool topological_sort_bfs(vector<int> adj[], int V)
// {
// store indegree of vertex.
//     vector<int> indegree(V, 0);
//     for (int i = 0; i < V; i++)
//     {
//         for (int x : adj[i])
//         {
//             indegree[x]++;
//         }
//     }
//     queue<int> q;
//     for (int i = 0; i < V; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }

//     bfsRec(adj, indegree, q);
//     for (int i = 0; i < V; i++)
//     {
//         if (indegree[i] != 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

bool topological_sort_bfs(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);
    // store all indegree of vertex
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int> q;
    // push all the vertex with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (q.empty() == false)
    {
        int front = q.front();
        q.pop();
        for (int x : adj[front])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
        count++;
    }
    return count != V;
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 0);
    printGraph(adj, V);
    // cout<<dfs(adj,V)<<endl ;
    cout << topological_sort_bfs(adj, V) << endl;
    return 0;
}
/*
    Problem Statement: Cycle Detection using directed graph.

    Input 1:
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

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

// using dfs

bool dfsRec(vector<int> adj[], int s, vector<bool> &visited, vector<bool> &visitedRec)
{
    visited[s] = true;
    visitedRec[s] = true;

    for (int x : adj[s])
    {
        if (visited[x] == false)
        {
            if (dfsRec(adj, x, visited, visitedRec))
            {
                return true;
            };
        }
        else if (visitedRec[x] == true)
        {
            return true;
        }
    }
    visitedRec[s] = false;
    return false;
}

bool dfs(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    vector<bool> visitedRec(V, false);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, i, visited, visitedRec))
            {
                return true;
            };
        }
    }
    return false;
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
    cout << dfs(adj, V) << endl;
    return 0;
}
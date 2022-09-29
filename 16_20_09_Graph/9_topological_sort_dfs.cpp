/*
    Problem Statement: Topological sort using DFS.
*/
#include <iostream>
#include <vector>
#include <stack>
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

void dfsRec(vector<int> adj[], int s, stack<int> &st, vector<bool> &visited)
{
    visited[s] = true;
    for (int x : adj[s])
    {
        if (visited[x] == false)
        {
            dfsRec(adj, x, st, visited);
        }
    }
    st.push(s);
}

void dfs_topological_sort(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            dfsRec(adj, i, st, visited);
        }
    }
    // print all the content of stack if its not empty

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
}
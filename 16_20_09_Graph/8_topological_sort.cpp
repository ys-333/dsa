/*
    Problem Statement: Topological Sort of Directed Cyclic Graph using BFS.


    This algorithm is known as kahn's algorithm

    Input 1:
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

   Output: 0 1 2 3

    Input 2:

     int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    Output: 0 1 2 3 4 5

    Input:
     addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);

    Output: 0 1 2 4 3

*/
#include <iostream>
#include <vector>
#include <stack>
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

void topological(vector<int> adj[], int V)
{
    // storing indegree of all the vertex in vector
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;

    // pushing vertex in queue with zero indegree

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // now printing all the vertex whose job is scheduleed and finished and then printing its dependency

    while (q.empty() == false)
    {
        int s = q.front();
        cout << s << " ";
        q.pop();
        for (int x : adj[s])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
}

int main()
{

    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    // printGraph(adj, V);
    // cout<<dfs(adj,V)<<endl ;
    topological(adj, V);
    return 0;
}
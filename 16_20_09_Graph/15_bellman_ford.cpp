/*
    ! Problem Statement: To find shortest distance in graph

    todo: Bellman ford has time complextiy of O(VE) which is far less efficient compare to time complextiy of dijikstra algorithm.
    ? But it outperform dijikstra when the graph is negative weighted.

    Bellman ford can detect negative weight cycle.

    todo: The first Loop ensure that we get shortest distance from the source vertex.
    todo: And second loop ensure that we can detect negative weight edge in grpah if there are any.


    Input:
    Graph g(4);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);
    g.bellman_ford(0);

    Output:
    0 -1 2 -2 
*/ 


#include<iostream>
#include<climits>
#include<vector>
using namespace std;

struct Node{
    int s,d,w ;
    Node(int source,int dest,int weight){
        s = source ;
        d = dest;
        w = weight ;
    }
};

class Graph{
    int V;
    vector<Node>adj;
    public:
    Graph(int v){
        V =v;
    }
    void addEdge(int s,int d,int w){
        Node temp(s,d,w);
        adj.push_back(temp);
    }
    void bellman_ford(int s){
        vector<int>dist(V,INT_MAX);
        dist[s] =0 ;
        // This loop ensure that we will get shortest distance from the root node.
        for(int i=0;i<V-1;i++){
            for(int j=0;j<adj.size();j++){
                auto temp = adj[j];
                int s = temp.s;
                int d = temp.d;
                int w =temp.w;
                if(dist[d]>dist[s]+w){
                    dist[d]= dist[s]+w;
                }
            }
        }
        // This loop find if the graph contain negative weight edges.
        for(int j=0;j<adj.size();j++){
            auto temp = adj[j];
            int s = temp.s;
            int d = temp.d;
            int w =temp.w;
            if(dist[d]>dist[s]+w){
                cout<<"contain negative weight cycles "<<endl ;
                break ;
            }
        }
        // print the distance
        for(int i=0;i<V;i++){
            cout<<dist[i]<<" " ;
        }

    }

};
int main()
{
     Graph g(4);
    g.addEdge(0,1,4);
    g.addEdge(0,2,8);
    g.addEdge(1,2,-8);
    g.addEdge(2,3,2);
    g.addEdge(3,1,3);
    g.bellman_ford(0);
}
## If graph is un-weighted and we need to find shortest path ---> BFS traversal. Time Complexity(O(V+E))

## If graph is weighted Directed and acyclic and we have to find shortest path---> Topological Sort. Time Complexity (O(V+E)).

## If graph is weighted, directed or undirected cyclic or acylic and we have to find shortest path -----> Dijikshtra algorithm. Time Complexity (O(Elog(E)+O(V)+))

<!-- Articulation point -->

Articulation point or cut-vertex ----> It is that vertex on removing which and its adjacent edges, it would split the Graph into two or more
strongly connected components.

Bridges ----> It is that edge on removing which our graph split into two or more strongly connected components.

# Kosaraju algorithm to find stronly connected components.

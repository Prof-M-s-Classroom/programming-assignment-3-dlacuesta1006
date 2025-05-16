[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Derek Mason Lacuesta

## Description
In this program we implement Prims Algorithm to find the minimum spanning tree(MST) of an undirected, weighted graph. The graph is represented using an adjacency matrix, and a custom-bult min heap is used to find and select the next vertex with the smallest edge weight during the MST contruction.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logv)         |
| Extract Min          | O(logv)         |
| Decrease Key         | O(logv)         |
| Prim’s MST Overall   | O(v^2 logv)     |

Insert inMin heap has O(logv) because in worst case the inserted node bubbles up the entire height of the heap which is logv for v vertices
Extract Min has O(logv) because after removing the root, heapify may run from top to bottom
Decrease Key has O(logv) because in worst case the key becomes the smallest and moves to the root
Prim's MST overall is O(v^2 logv) because for each of n vertices they extract the min vertex which is O(n logv) then for each vertx scan all of n neighbors because of adjacency matrix which is O(n) and if the neighbor is in the heap and the edge is better call decrease key which is O(logv)

## Test Case Description

First I noticed that the graph is undirected and connected so a MST should exist. Then the number of vertices is known and is going to the Graph constructor. Duplicate edges are not added, each call to addedge(u, v, w) overwrites any previous weight between u and v

Input:  Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

Output:
Edges
0 : 1	2
1 : 2	3
0 : 3	6
1 : 4	5
Total Weight: 16

I tried out basic connectivity 5 nodes, known MST and correctly printed MST
V=1 single node grpah there was no output
V=2 which is one edge a minimal graph with a single connection and one edge printed
All edges same weight with uniform weight edges and any valid MST with the same total weight printed
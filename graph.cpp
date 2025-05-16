#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* parent = new int[numVertices];
    int* key = new int[numVertices];
    MinHeap minHeap(numVertices);

    for (int v = 0; v < numVertices; v++) {
        key[v] = INT_MAX;
        parent[v] = -1;
        minHeap.insert(v, key[v]);
    }

    key[0] = 0;
    minHeap.decreaseKey(0,0);

    int totalWeight = 0;

    while (!minHeap.isEmpty()) {
        int u = minHeap.extractMin();
        totalWeight += key[u];

        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] && minHeap.isInMinHeap(v) && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
                minHeap.decreaseKey(v, key[v]);
            }
        }
    }
    std::cout << "Edges" << std::endl;
    for (int i = 1; i < numVertices; i++)
        std::cout << parent[i] << " : " << i << "\t" << adjMatrix[i][parent[i]] << "\n";
    std::cout << "Total Weight: " << totalWeight << "\n";

    delete[] parent;
    delete[] key;
}


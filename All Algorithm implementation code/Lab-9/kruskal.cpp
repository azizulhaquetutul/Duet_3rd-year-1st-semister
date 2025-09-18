#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // For measuring execution time

using namespace std;

// Define a structure for an edge
struct Edge {
    int u, v, weight;
};

// Make-set operation: Initialize each node to be its own parent and rank as 0
void makeSet(int V, vector<int> &parent, vector<int> &rank) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find-set operation: Find the representative (root) of the set that contains the node
int findSet(int node, vector<int> &parent) {
    if (parent[node] != node) {
        parent[node] = findSet(parent[node], parent);  // Path compression
    }
    return parent[node];
}

// Union operation: Merge two sets by rank
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int rootU = findSet(u, parent);
    int rootV = findSet(v, parent);

    if (rootU != rootV) {
        // Union by rank
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Function to implement Kruskal's Algorithm
void kruskal(int V, const vector<vector<int>> &adjMatrix) {
    vector<Edge> edges;

    // Convert the adjacency matrix into a list of edges
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) { // Avoid duplicating edges
            if (adjMatrix[i][j] != 0) {  // Skip 0 or no connection
                edges.push_back({i, j, adjMatrix[i][j]});
            }
        }
    }

    // Sort the edges based on their weights
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;  // Sort by weight in ascending order
    });

    vector<int> parent(V);
    vector<int> rank(V);

    // Initialize disjoint sets
    makeSet(V, parent, rank);

    int totalWeight = 0;  // To store the total weight of the MST
    vector<Edge> mstEdges;  // To store the MST edges

    // Measure the time for MST computation
    auto start = chrono::high_resolution_clock::now();

    // Process each edge in increasing order of weight
    for (Edge edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // If including this edge does not form a cycle
        if (findSet(u, parent) != findSet(v, parent)) {
            unionSets(u, v, parent, rank);
            mstEdges.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    // Output the MST edges and their weights
    cout << "Edge    Weight\n";
    for (Edge edge : mstEdges) {
        cout << edge.u << " - " << edge.v << "   " << edge.weight << endl;
    }
    cout << "Minimum weight of the MST: " << totalWeight << endl;
    cout << "Time taken to calculate MST: " << elapsed.count()*1000000000 << " seconds\n";
}

int main() {
    // Example graph represented as an adjacency matrix
    int V = 9;  // Number of vertices
    vector<vector<int>> adjMatrix = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0},
    };

    // Call the Kruskal's algorithm function
    kruskal(V, adjMatrix);

    return 0;
}


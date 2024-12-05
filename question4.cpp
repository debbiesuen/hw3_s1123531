//Suen Man Ying S1123531 05Dec2024

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight; // u and v are the vertices, and weight is the weight of the edge
    // Constructor to initialize the edge
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

// Function to find the root of an element using path compression
int find(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent);  // Path compression for optimization
    }
    return parent[u];
}

// Function to perform the union of two sets using union by rank
void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);  // Find the root of set containing u
    int rootV = find(v, parent);  // Find the root of set containing v

    // If both vertices belong to different sets, perform the union
    if (rootU != rootV) {
        // Union by rank: Attach the smaller tree under the root of the larger tree
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;  // Increase rank if the tree heights were the same
        }
    }
}

// Kruskal's Algorithm to find the Minimum Spanning Tree (MST)
int kruskal(int V, vector<Edge>& edges) {
    // Step 1: Sort all edges in increasing order of their weight
    sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2) {
        return e1.weight < e2.weight;  // Sort edges by weight in ascending order
    });

    // Step 2: Initialize Union-Find data structure (parent array and rank array)
    vector<int> parent(V);  // parent[i] will be the representative of vertex i
    vector<int> rank(V, 0); // rank[i] will keep track of the tree height for union by rank

    // Initially, each vertex is its own parent (disjoint sets)
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;  // To store the sum of the weights of the edges in the MST
    int edgesInMST = 0; // To track the number of edges added to the MST

    // Step 3: Process each edge one by one
    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // Step 4: If u and v belong to different sets (i.e., no cycle will be formed)
        // we add the edge to the MST and unite the sets
        if (find(u, parent) != find(v, parent)) {
            mstWeight += edge.weight;  // Add edge weight to MST weight
            unite(u, v, parent, rank); // Union the two sets containing u and v
            edgesInMST++;              // Increment the edge count in MST

            // If we've added V-1 edges to the MST (where V is the number of vertices),
            // we can stop, as MST is complete.
            if (edgesInMST == V - 1) {
                break;
            }
        }
    }

    return mstWeight;  // Return the total weight of the MST
}

int main() {
    int V, E;  // Number of vertices (V) and edges (E)
    cin >> V >> E;  // Take input for V and E

    // Vector to store all the edges in the graph
    vector<Edge> edges;

    // Step 1: Read the edges from input
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;  // Read each edge: u, v and its weight
        edges.push_back(Edge(u, v, weight));  // Store the edge in the edges list
    }

    // Step 2: Call Kruskal's algorithm to get the total weight of the MST
    int mstWeight = kruskal(V, edges);

    // Step 3: Output the result (sum of weights of the MST)
    cout << mstWeight << endl;

    return 0;
}

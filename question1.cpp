//Suen Man Ying S1123531 05Dec2024

#include <iostream>
#include <vector>
#include <algorithm>  // For sorting the adjacency lists
using namespace std;

// Function to create the adjacency list
vector<vector<int>> createAdjacencyList(int V, int E, const vector<pair<int, int>>& edges) {
    // Step 1: Initialize an empty adjacency list for each vertex.
    vector<vector<int>> adjList(V);
    
    // Step 2: Iterate over each edge and add the connection between the two vertices.
    for (const auto& edge : edges) {
        int u = edge.first;  // First vertex of the edge
        int v = edge.second; // Second vertex of the edge
        
        // Add the edge in both directions (since the graph is undirected)
        adjList[u].push_back(v);  // Vertex u is connected to v
        adjList[v].push_back(u);  // Vertex v is connected to u
    }
    
    // Step 3: Sort the adjacency list for each vertex to match the expected output
    for (int i = 0; i < V; i++) {
        sort(adjList[i].begin(), adjList[i].end());  // Sort the connected nodes for each vertex
    }
    
    return adjList;  // Return the completed adjacency list
}

int main() {
    int V, E;
    cin >> V >> E;  // Step 1: Read the number of vertices and edges from input

    vector<pair<int, int>> edges;
    
    // Step 2: Read the edges and store them in a vector of pairs
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;  // Read each edge (two integers)
        edges.push_back({u, v});  // Add the edge to the edges vector
    }
    
    // Step 3: Call the function to create the adjacency list
    vector<vector<int>> adjList = createAdjacencyList(V, E, edges);
    
    // Step 4: Output the adjacency list
    for (int i = 0; i < V; i++) {
        cout << "[";  // Print the opening bracket for each node's adjacency list
        
        // Print each neighbor of the current node
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j];
            if (j != adjList[i].size() - 1) {
                cout << ",";  // Print a comma between neighbors (except for the last neighbor)
            }
        }
        
        cout << "]" << endl;  // Close the bracket and move to the next line
    }
    
    return 0;  // Return from the main function
}

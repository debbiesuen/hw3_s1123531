//Suen Man Ying S1123531 05Dec2024

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to perform DFS traversal starting from vertex 0
void dfs(int node, const vector<vector<int>>& adj, unordered_set<int>& visited, vector<int>& dfsResult) {
    // Step 1: Mark the current node as visited
    visited.insert(node);

    // Step 2: Add the current node to the DFS result
    dfsResult.push_back(node);

    // Step 3: Visit all the neighbors of the current node
    for (int neighbor : adj[node]) {
        if (visited.find(neighbor) == visited.end()) {  // If the neighbor hasn't been visited
            dfs(neighbor, adj, visited, dfsResult);  // Recursively visit the neighbor
        }
    }
}

int main() {
    int V;
    // Input the number of vertices (V)
    cin >> V;

    // Initialize adjacency list with V vertices
    vector<vector<int>> adj(V);

    // Input adjacency list (each row represents the neighbors of a vertex)
    for (int i = 0; i < V; i++) {
        int neighbor;
        while (cin >> neighbor) {
            adj[i].push_back(neighbor);
            if (cin.peek() == '\n') break;  // Break the loop if the line ends
        }
    }

    // Create a set to keep track of visited nodes
    unordered_set<int> visited;
    // This will store the DFS traversal order
    vector<int> dfsResult;

    // Perform DFS starting from vertex 0
    dfs(0, adj, visited, dfsResult);

    // Output the DFS traversal order
    cout << "[";
    for (int i = 0; i < dfsResult.size(); i++) {
        cout << dfsResult[i];
        if (i != dfsResult.size() - 1) cout << ", ";  // Print commas between elements except for the last one
    }
    cout << "]" << endl;

    return 0;
}

//Suen Man Ying S1123531 05Dec2024

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Function to perform BFS starting from vertex 0
vector<int> bfsTraversal(const vector<vector<int>>& adj) {
    int V = adj.size();  // Number of vertices in the graph
    vector<int> bfsResult;  // This will store the BFS traversal order
    unordered_set<int> visited;  // Set to keep track of visited nodes
    queue<int> q;  // Queue for BFS
    
    // Step 1: Start BFS from vertex 0
    q.push(0);  // Enqueue the starting node (0)
    visited.insert(0);  // Mark node 0 as visited
    
    // Step 2: Perform BFS until the queue is empty
    while (!q.empty()) {
        int node = q.front();  // Get the front element (current node)
        q.pop();  // Remove the front element from the queue
        bfsResult.push_back(node);  // Add the current node to the BFS result
        
        // Step 3: Visit all unvisited neighbors of the current node
        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {  // If the neighbor hasn't been visited
                visited.insert(neighbor);  // Mark it as visited
                q.push(neighbor);  // Enqueue the neighbor for future exploration
            }
        }
    }
    
    // Step 4: Return the final BFS traversal order
    return bfsResult;
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

    // Perform BFS and get the result
    vector<int> result = bfsTraversal(adj);

    // Output the BFS traversal order
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";  // Print commas between elements except for the last one
    }
    cout << "]" << endl;

    return 0;
}

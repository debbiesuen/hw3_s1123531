# hw3_s1123531

Question: 1
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

Input:
6 8
0 1
0 3
1 2
1 4
2 4
2 5
3 4
4 5

Output: 
[1,3]
[0,2,4]
[1,4,5]
[0,4]
[1,2,3,5]
[2,4]


Question: 2
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.
Note: Do traverse in the same order as they are in the adjacency list.

Input: 
4
1 2
0 3
0 3
1 2

Output: [0, 1, 2, 3]


Question: 3
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.
Note: Do traverse in the same order as they are in the adjacency list.

Input:
4
1 2
0 3
0 1 3
1 2

Output: [0, 1, 3, 2]



Question: 4
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
4 5
0 1 7
0 2 5
1 2 3
1 3 9
2 3 2


Output:
10

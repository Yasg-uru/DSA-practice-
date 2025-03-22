/*
    A complete graph is a graph in which every pair of distinct vertices is connected by an edge.
    In an undirected complete graph with 'V' vertices, the total number of edges should be:
        Total Edges = (V * (V - 1)) / 2
    In this solution, we find the number of complete connected components in the given graph.
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Depth-First Search (DFS) to explore components
    void performDFS(int node, unordered_map<int, vector<int>>& adjacencyList, 
                    vector<bool>& visited, int& nodeCount, int& edgeCount) {
        visited[node] = true;
        nodeCount++;
        edgeCount += adjacencyList[node].size();
        
        for (auto& neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                performDFS(neighbor, adjacencyList, visited, nodeCount, edgeCount);
            }
        }
    }
    
    int countCompleteComponents(int totalNodes, vector<vector<int>>& edges) {
        vector<bool> visited(totalNodes, false);
        unordered_map<int, vector<int>> adjacencyList;
        
        // Construct adjacency list
        for (auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
        }
        
        int completeComponentCount = 0;
        
        // Traverse all nodes
        for (int i = 0; i < totalNodes; i++) {
            if (visited[i]) continue; // Skip already visited nodes
            
            int nodeCount = 0;
            int edgeCount = 0;
            
            // Perform DFS to explore the component
            performDFS(i, adjacencyList, visited, nodeCount, edgeCount);
            
            // A complete component must have exactly (V * (V - 1)) / 2 edges
            int requiredEdges = (nodeCount * (nodeCount - 1)) / 2;
            edgeCount /= 2; // Each edge was counted twice in an undirected graph
            
            if (requiredEdges == edgeCount) {
                completeComponentCount++;
            }
        }
        
        return completeComponentCount;
    }
};

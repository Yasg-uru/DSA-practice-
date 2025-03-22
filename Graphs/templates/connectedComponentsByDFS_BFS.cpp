/* 
    Graph Connected Components Template
    ----------------------------------
    This template provides a generic structure to solve connected component-related problems
    in undirected graphs. It uses Depth-First Search (DFS) to traverse components.
*/

#include <vector>
#include <unordered_map>
using namespace std;

class GraphSolver {
public:
    // DFS function to explore a connected component
    void exploreComponent(int node, unordered_map<int, vector<int>>& adjacencyList, 
                          vector<bool>& visited, int& nodeCount, int& edgeCount) {
        visited[node] = true;
        nodeCount++;
        edgeCount += adjacencyList[node].size();
        
        for (auto& neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                exploreComponent(neighbor, adjacencyList, visited, nodeCount, edgeCount);
            }
        }
    }
    
    int countConnectedComponents(int totalNodes, vector<vector<int>>& edges) {
        vector<bool> visited(totalNodes, false);
        unordered_map<int, vector<int>> adjacencyList;
        
        // Construct adjacency list
        for (auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
        }
        
        int componentCount = 0;
        
        // Traverse all nodes
        for (int i = 0; i < totalNodes; i++) {
            if (visited[i]) continue; // Skip already visited nodes
            
            int nodeCount = 0;
            int edgeCount = 0;
            
            // Perform DFS to explore the component
            exploreComponent(i, adjacencyList, visited, nodeCount, edgeCount);
            
            // If needed, modify this condition to fit specific problem requirements
            int requiredEdges = (nodeCount * (nodeCount - 1)) / 2;
            edgeCount /= 2; // Each edge was counted twice in an undirected graph
            
            if (requiredEdges == edgeCount) {
                componentCount++;
            }
        }
        
        return componentCount;
    }
};

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Function to find the largest color value in a directed graph.
     * Uses Topological Sort (Kahn's Algorithm) with Dynamic Programming on Graphs.
     *
     * @param colors A string where colors[i] represents the color of node i.
     * @param edges A 2D vector where each edge[i] = [u, v] represents a directed edge from node u to v.
     * @return The maximum color frequency in any valid path, or -1 if a cycle exists.
     */
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();  // Number of nodes in the graph

        // Step 1: Construct the Graph & Compute In-Degree
        vector<int> inDegree(n, 0);  // In-degree array to track incoming edges
        unordered_map<int, vector<int>> adjList; // Adjacency list representation of the graph
        
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            adjList[from].push_back(to);
            inDegree[to]++;
        }

        // Step 2: Initialize BFS Queue and Color Frequency DP Table
        queue<int> q;
        vector<vector<int>> colorCount(n, vector<int>(26, 0)); // DP table to store max color frequency at each node
        int processedNodes = 0;  // Count of nodes processed in Topological Sort
        int maxColorValue = 0;   // Stores the maximum color frequency in any valid path

        // Step 3: Add Nodes with In-Degree = 0 to the Queue
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                colorCount[i][colors[i] - 'a'] = 1;  // Mark the color of the starting node
            }
        }

        // Step 4: Process Nodes Using BFS (Topological Sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processedNodes++;

            // Update maximum color frequency for this node
            maxColorValue = max(maxColorValue, *max_element(colorCount[node].begin(), colorCount[node].end()));

            // Traverse all neighbors (directed edges from current node)
            for (int neighbor : adjList[node]) {
                // Step 5: Propagate Color Frequency to Neighbor
                for (int i = 0; i < 26; i++) {
                    colorCount[neighbor][i] = max(colorCount[neighbor][i], colorCount[node][i] + (colors[neighbor] - 'a' == i));
                }

                // Reduce in-degree and push to queue if in-degree becomes 0
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 6: If not all nodes are processed, a cycle exists
        return (processedNodes == n) ? maxColorValue : -1;
    }
};

// Driver function for testing
int main() {
    Solution sol;

    // Example 1: No cycle, valid path with max color frequency
    string colors1 = "abaca";
    vector<vector<int>> edges1 = {{0,1}, {0,2}, {2,3}, {3,4}};
    cout << "Largest Color Value: " << sol.largestPathValue(colors1, edges1) << endl;  // Output: 3

    // Example 2: Graph contains a cycle
    string colors2 = "a";
    vector<vector<int>> edges2 = {{0,0}};
    cout << "Largest Color Value: " << sol.largestPathValue(colors2, edges2) << endl;  // Output: -1

    return 0;
}

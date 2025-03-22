/**
 * @file max_probability_path.cpp
 * @brief Solution for "1514. Path with Maximum Probability" problem.
 * 
 * This solution finds the path with the highest probability of success in an 
 * undirected weighted graph using a priority queue (Dijkstra-like approach).
 *
 * - **Graph Representation:** Adjacency list using `unordered_map<int, vector<pair<int, double>>>`
 * - **Algorithm Used:** Modified Dijkstra with a max-heap (priority queue)
 * - **Time Complexity:** O(E log V) (E = edges, V = vertices)
 * - **Space Complexity:** O(V + E)
 *
 * Example:
 * ```
 * Input:
 * n = 3
 * edges = [[0,1],[1,2],[0,2]]
 * succProb = [0.5,0.5,0.3]
 * start = 0, end = 2
 *
 * Output: 0.30000
 * ```
 *
 * @author Your Name
 * @date 2024
 */

 #include <iostream>
 #include <vector>
 #include <queue>
 #include <unordered_map>
 
 using namespace std;
 
 class Solution {
 public:
     /**
      * @brief Finds the maximum probability path from `src` to `dest` in a weighted graph.
      * 
      * @param n Number of nodes
      * @param edges Edges in the graph, where each edge connects two nodes
      * @param succProb Success probabilities associated with each edge
      * @param src Starting node
      * @param dest Destination node
      * @return Maximum probability to reach `dest` from `src`
      */
     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dest) {
         vector<double> result(n, 0.0);  // Stores max probability to reach each node
         unordered_map<int, vector<pair<int, double>>> adj;  // Adjacency list
 
         // Build adjacency list
         for (int i = 0; i < edges.size(); i++) {
             int u = edges[i][0], v = edges[i][1];
             double probability = succProb[i];
             adj[u].push_back({v, probability});
             adj[v].push_back({u, probability});
         }
 
         // Max-Heap to process highest probability paths first
         priority_queue<pair<double, int>> pq;
         pq.push({1.0, src});
         result[src] = 1.0;  // Start node probability should be 1.0
 
         while (!pq.empty()) {
             double p = pq.top().first;
             int node = pq.top().second;
             pq.pop();
 
             for (auto& [nbr, np] : adj[node]) {
                 if (p * np > result[nbr]) {  // Update max probability for neighbor
                     result[nbr] = p * np;
                     pq.push({result[nbr], nbr});
                 }
             }
         }
 
         return result[dest];  // Maximum probability to reach `dest`
     }
 };
 
 // Example usage for testing
 int main() {
     Solution sol;
     int n = 3;
     vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
     vector<double> succProb = {0.5, 0.5, 0.3};
     int start = 0, end = 2;
     
     cout << "Maximum Probability: " << sol.maxProbability(n, edges, succProb, start, end) << endl;
     
     return 0;
 }
 
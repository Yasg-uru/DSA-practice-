#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        int Q = queries.size(); // Number of queries
        
        // Pair queries with their indices for sorting
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < Q; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Min-heap (priority queue) to process cells in increasing order of values
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        // Visited matrix to track processed cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        // Result array initialized with zero values
        vector<int> result(Q, 0);
        
        // Directions for movement: right, down, left, up
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int points = 0; // Counter for valid points below the query threshold
        
        // Process each query
        for (auto& [queryVal, index] : sortedQueries) {
            // Expand the grid until the smallest element is >= queryVal
            while (!pq.empty() && pq.top().first < queryVal) {
                auto [currVal, coord] = pq.top();
                int i = coord.first;
                int j = coord.second;
                pq.pop();
                points++;
                
                // Explore adjacent cells
                for (auto& dir : directions) {
                    int newI = i + dir[0];
                    int newJ = j + dir[1];
                    
                    // Check bounds and if already visited
                    if (newI >= 0 && newJ >= 0 && newI < m && newJ < n && !visited[newI][newJ]) {
                        pq.push({grid[newI][newJ], {newI, newJ}});
                        visited[newI][newJ] = true;
                    }
                }
            }
            
            // Store the number of reachable points for the current query
            result[index] = points;
        }
        
        return result;
    }
};
/*
    Problem: Parallel Courses III (LeetCode 2050)
    Approach: Topological Sorting (Kahn's Algorithm) + Dynamic Programming

    - Build a Directed Acyclic Graph (DAG) from prerequisite relations.
    - Use Kahn’s Algorithm (BFS + Topological Sort) to determine the order of courses.
    - Maintain a `maxTime` array to track the longest time required to complete each course.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Step 1: Build adjacency list & compute in-degrees
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), maxTime(n, 0);
        
        for (auto& relation : relations) {
            int u = relation[0] - 1; // Convert 1-based index to 0-based
            int v = relation[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        // Step 2: Initialize queue with courses having no prerequisites
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                maxTime[i] = time[i]; // Base case: Course takes its own time if independent
            }
        }
        
        // Step 3: Process courses in topological order
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : adj[curr]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[curr] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 4: Return the longest time required among all courses
        return *max_element(maxTime.begin(), maxTime.end());
    }
};

// Example Usage
int main() {
    Solution solution;
    vector<vector<int>> relations = {{1, 3}, {2, 3}};
    vector<int> time = {3, 2, 5};
    int n = 3;
    cout << "Minimum time to complete all courses: " << solution.minimumTime(n, relations, time) << endl;
    return 0;
}

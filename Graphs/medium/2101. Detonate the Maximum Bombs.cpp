/*
    🔥 Problem: Maximum Detonation (Graph & DFS Approach)
    -----------------------------------------------------
    Given a set of bombs, each represented by (x, y, r):
    - (x, y) are the coordinates of the bomb.
    - r is the explosion radius.
    
    If one bomb explodes, it can trigger another bomb within its radius, 
    forming a **chain reaction**.

    🚀 **Goal:** Find the maximum number of bombs that can be detonated starting from any single bomb.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    /*
        🔍 Depth-First Search (DFS) Function:
        - Traverses the adjacency list to explore detonations.
        - Marks visited bombs to avoid redundant checks.
    */
    void DFS(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int currNode) {
        visited.insert(currNode);  // Mark bomb as detonated
        for (auto& nbr : adj[currNode]) {
            if (visited.find(nbr) == visited.end()) {
                DFS(adj, visited, nbr);
            }
        }
    }

    /*
        💣 Maximum Detonation Function:
        - Constructs a **directed graph** where an edge (u → v) means bomb `u` can trigger bomb `v`.
        - Uses DFS to determine the maximum number of bombs that can be detonated.
    */
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> adj;  // Graph adjacency list
        int n = bombs.size();

        /*
            🔢 Step 1: Build Graph
            - Compute the Euclidean distance between each pair of bombs.
            - If a bomb's explosion radius covers another bomb, add a **directed edge**.
        */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;  // Ignore self

                // Bomb i details
                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long r1 = bombs[i][2];

                // Bomb j details
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                // ✅ Distance Calculation (Avoiding Floating Point Errors)
                long long distanceSquared = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                long long radiusSquared = r1 * r1;

                // 🔗 If bomb `i` can reach bomb `j`, add a directed edge `i → j`
                if (radiusSquared >= distanceSquared) {
                    adj[i].push_back(j);
                }
            }
        }

        /*
            🔢 Step 2: Traverse Graph using DFS
            - Start DFS from each bomb and count how many bombs detonate.
            - Track the maximum detonated bombs count.
        */
        int maxAns = 1;
        unordered_set<int> visited;

        for (int i = 0; i < n; i++) {
            visited.clear();
            DFS(adj, visited, i);
            int detonatedBombsCount = visited.size();
            maxAns = max(maxAns, detonatedBombsCount);
        }

        return maxAns;
    }
};

/*
    📌 Distance Calculation Formula:
    --------------------------------
    The distance between two points (x1, y1) and (x2, y2) is:
    
        d = sqrt((x2 - x1)^2 + (y2 - y1)^2)

    - Instead of using `sqrt()`, we compare **squared distances** to avoid floating point precision issues:

        If r1^2 ≥ (x2 - x1)^2 + (y2 - y1)^2
        → Then bomb `i` can detonate bomb `j`.

    This makes calculations **faster & more accurate** by avoiding unnecessary floating-point operations.
*/

/* 🧪 Example Test Case */
int main() {
    Solution sol;
    vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
    cout << "Maximum bombs detonated: " << sol.maximumDetonation(bombs) << endl;
    return 0;
}

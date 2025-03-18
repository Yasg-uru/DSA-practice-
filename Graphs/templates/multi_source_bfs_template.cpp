#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Directions for 4-way traversal (Up, Down, Left, Right)
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class MultiSourceBFS {
public:
    int bfs(vector<vector<int>>& grid, int sourceValue, int targetValue) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // Step 1: Push all source nodes into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == sourceValue) {  
                    q.push({i, j});
                }
            }
        }

        int steps = 0;

        // Step 2: Standard BFS traversal
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int ni = i + dir[0], nj = j + dir[1];

                    // Step 3: Check boundary conditions and constraints
                    if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == targetValue) {
                        q.push({ni, nj});
                        grid[ni][nj] = sourceValue;  // Mark as visited (or modified)
                    }
                }
            }
            steps++;
        }

        // Step 4: Optional - Check if all target values were reached
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == targetValue) {  
                    return -1;  // Some target cells were unreachable
                }
            }
        }

        return (steps > 0) ? steps - 1 : 0;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    MultiSourceBFS obj;
    int result = obj.bfs(grid, 2, 1);  // Rotting Oranges Example: 2 -> Rotten, 1 -> Fresh
    cout << "Minimum Steps: " << result << endl;
    
    return 0;
}

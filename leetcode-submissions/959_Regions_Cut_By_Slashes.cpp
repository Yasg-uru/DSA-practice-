class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n * 3, vector<int>(n * 3, 0));
        
        // Expand the grid to a 3x3 grid for each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    v[i * 3][j * 3 + 2] = 1;
                    v[i * 3 + 1][j * 3 + 1] = 1;
                    v[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    v[i * 3][j * 3] = 1;
                    v[i * 3 + 1][j * 3 + 1] = 1;
                    v[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
       
        
        // Perform DFS to count regions
        int regions = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (v[i][j] == 0) {  // Unvisited part of a region
                    dfs(v, i, j);
                    regions++;
                }
            }
        }
        
        return regions;
    }

private:
    void dfs(vector<vector<int>>& v, int i, int j) {
        int n = v.size();
        if (i < 0 || j < 0 || i >= n || j >= n || v[i][j] == 1) {
            return;
        }
        v[i][j] = 1; // Mark as visited
        dfs(v, i + 1, j); // Down
        dfs(v, i - 1, j); // Up
        dfs(v, i, j + 1); // Right
        dfs(v, i, j - 1); // Left
    }
};


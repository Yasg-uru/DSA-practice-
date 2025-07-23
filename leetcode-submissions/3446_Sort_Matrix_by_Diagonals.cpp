class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         int n = grid.size();
    map<int, vector<int>> diagonals;

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diagonals[i - j].push_back(grid[i][j]);
        }
    }

 
    for (auto& [d, values] : diagonals) {
        if (d >= 0) {
            sort(values.rbegin(), values.rend()); 
        } else {
            sort(values.begin(), values.end());   
        }
    }

  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = diagonals[i - j].front();
            diagonals[i - j].erase(diagonals[i - j].begin());
        }
    }

    return grid;
    }
};
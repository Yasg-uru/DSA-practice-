class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        if (grid.empty()) {
        return 0;
    }
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    int top = INT_MAX, bottom = INT_MIN;
    int left = INT_MAX, right = INT_MIN;
    
    // Find the bounding box
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 1) {
                top = std::min(top, r);
                bottom = std::max(bottom, r);
                left = std::min(left, c);
                right = std::max(right, c);
            }
        }
    }
    
    // Calculate the area of the minimum bounding box
    int height = bottom - top + 1;
    int width = right - left + 1;
    
    return height * width;
    }
};
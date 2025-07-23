class Solution {
public:
    void fill(vector<vector<int>>& mat, int startRow, int startCol, int endRow, int endCol, int starter) {
        int top = startRow, bottom = endRow, left = startCol, right = endCol;
        int direction = 0;
        while(top <= bottom && left <= right) {
            if(direction == 0) {
                for(int row = top; row <= bottom; row++) {
                    mat[row][left] = starter--;
                }
                left++;
            } else if(direction == 1) {
                for(int col = left; col <= right; col++) {
                    mat[bottom][col] = starter--;
                }
                bottom--;
            } else if(direction == 2) {
                for(int row = bottom; row >= top; row--) {
                    mat[row][right] = starter--;
                }
                right--;
            } else {
                for(int col = right; col >= left; col--) {
                    mat[top][col] = starter--;
                }
                top++;
            }
            direction = (direction + 1) % 4;
        }
    }

    vector<vector<int>> specialGrid(int N) {
        int s = pow(2, N);
        vector<vector<int>> mat(s, vector<int>(s));
        int center = s / 2;
        int total = s * s;

      
        int starter = (s * s) / 4;
        fill(mat, 0, center, center - 1, s - 1, starter - 1);        
        fill(mat, center, center, s - 1, s - 1, 2 * starter - 1);     
        fill(mat, center, 0, s - 1, center - 1, 3 * starter - 1);     
        fill(mat, 0, 0, center - 1, center - 1, 4 * starter - 1);      

        return mat;
    }
};

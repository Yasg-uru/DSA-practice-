class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // Get dimensions of the box
        int m = box.size();
        int n = box[0].size();

        // Create the result matrix with transposed dimensions
        vector<vector<char>> result(n, vector<char>(m));

        // Step 1: Calculate the transpose of the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = box[i][j];
            }
        }

        // Step 2: Reverse each row in the result matrix to achieve a 90-degree rotation
        for (vector<char>& row : result) {
            reverse(row.begin(), row.end());
        }

        // Step 3: Simulate the gravity effect
        for (int j = 0; j < n; j++) { // Loop through columns
            for (int i = m - 1; i >= 0; i--) { // Loop from bottom to top of the column
                if (result[i][j] == '.') { // If the current cell is empty
                    int stoneRow = -1;
                    for (int k = i - 1; k >= 0; k--) { // Look upwards for a stone
                        if (result[k][j] == '*') { // Obstacle found
                            break;
                        } else if (result[k][j] == '#') { // Stone found
                            stoneRow = k;
                            break;
                        }
                    }
                    if (stoneRow != -1) { // If a stone was found above
                        result[stoneRow][j] = '.'; // Clear the original stone position
                        result[i][j] = '#'; // Move the stone to the empty position
                    }
                }
            }
        }

        return result; // Return the final rotated and adjusted box
    }
};

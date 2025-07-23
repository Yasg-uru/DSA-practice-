class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
          int n = bottomLeft.size();
        long long maxSide = 0;

        for (int i = 0; i < n; ++i) {
            // Find the minimum side length for each rectangle
            long long side = std::min(topRight[i][0] - bottomLeft[i][0], topRight[i][1] - bottomLeft[i][1]);
            maxSide = std::max(maxSide, side);
        }

        // Calculate the largest square area
        return maxSide * maxSide;
    }
};
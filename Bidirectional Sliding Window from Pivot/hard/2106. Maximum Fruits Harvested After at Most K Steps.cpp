class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        // Extract positions and prefix sums of fruits
        vector<int> prefixSum(n), positions(n);
        for (int i = 0; i < n; i++) {
            positions[i] = fruits[i][0]; // fruit position
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0); // cumulative fruit count
        }

        int maxFruits = 0;

        // Try all possible splits of the k steps: d in one direction, remaining in the other
        for (int d = 0; d <= k / 2; d++) {
            int remaining = k - 2 * d;

            // ----- Case 1: Move d steps left, then remaining steps right -----
            int i = startPos - d;
            int j = startPos + remaining;

            // Find the range of fruit positions [i, j]
            int left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            int right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            // If valid range, update maxFruits using prefix sum
            if (left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

            // ----- Case 2: Move d steps right, then remaining steps left -----
            i = startPos - remaining;
            j = startPos + d;

            left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if (left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }
        }

        return maxFruits;
    }
};

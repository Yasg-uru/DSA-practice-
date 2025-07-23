
class Solution {
public:
    unordered_map<int, int> mp;  // Stores index of each element
    unordered_map<int, unordered_map<int, int>> dp; // Memoization table

    int solve(int j, int k, vector<int>& arr) {
        if (dp[j].count(k)) return dp[j][k]; // Check memoization

        int target = arr[k] - arr[j];
        if (mp.count(target) && mp[target] < j) {
            dp[j][k] = solve(mp[target], j, arr) + 1;
        } else {
            dp[j][k] = 2; // Base case: min length of a sequence
        }
        return dp[j][k];
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        // Map values to their indices
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int maxLength = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr);
                if (length >= 3) {
                    maxLength = max(maxLength, length);
                }
            }
        }

        return maxLength;
    }
};
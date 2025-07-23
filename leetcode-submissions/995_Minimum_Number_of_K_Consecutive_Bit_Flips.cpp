class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        // Tracks at what index flipping has been done
        vector<bool> isFlipped(n, false);

        // Tracks the final answer
        int ans = 0;

        // Keeps track of the current number of flips till index i
        int flippedCount = 0;

        for (int i = 0; i < n; i++) {

            // Check if we have crossed a subarray range
            // If yes, then decrease flippedCount
            if (i >= k && isFlipped[i - k]) {
                flippedCount--;
            }

            // Summarised case of when flipping is needed
            // We need to flip if the current flippedCount is even and nums[i] is 0
            // or if the current flippedCount is odd and nums[i] is 1
            if (flippedCount % 2 == nums[i]) {
                // Check if we are outside the threshold for correcting flips
                if (i + k > n) {
                    return -1; // Not enough elements left to flip
                }
                ans++; // Increment the answer since we are flipping
                flippedCount++; // Increment the flipped count
                isFlipped[i] = true; // Mark this index as flipped
            }
        }
        return ans; // Return the minimum number of K consecutive bit flips
    }
};
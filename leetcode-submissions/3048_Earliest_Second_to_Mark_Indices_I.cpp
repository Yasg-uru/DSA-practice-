class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();

        std::unordered_set<int> markedIndices;

        for (int second = 1; second <= m; ++second) {
            int changeIndex = changeIndices[second - 1];

            if (markedIndices.count(changeIndex)) {
                // Index is already marked, do nothing
            } else if (nums[changeIndex - 1] > 0) {
                // Decrement the value at changeIndex if it's greater than 0
                nums[changeIndex - 1]--;
            } else {
                // Mark the index if its value is already 0
                markedIndices.insert(changeIndex);
            }

            // Check if all indices are marked
            if (markedIndices.size() == n) {
                return second;
            }
        }

        // If not all indices are marked, return -1
        return -1;
    }
};
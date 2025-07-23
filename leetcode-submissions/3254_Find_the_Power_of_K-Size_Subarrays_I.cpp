class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size()-k+1, -1);
        for (int i = 0; i <= nums.size() - k; i++) {
            int locmax = INT_MIN;
            bool hasMax = true;
            for (int j = i; j < i + k; j++) {
                // Check for increasing sequence condition
                if (j < i + k - 1 && nums[j] >= nums[j + 1]) {
                    hasMax = false;
                    break;
                }
                locmax = max(locmax, nums[j]);
            }
            if (hasMax) {
                ans[i] = locmax;
            }
        }
        return ans;
    }
};

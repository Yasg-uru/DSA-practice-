#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int count = 1;
        
        // Check the first window of size k
        for (int i = 1; i < k; i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                count++;
            } else {
                count = 1;
            }
        }
        
        // If the first window has k consecutive increasing numbers, store the last element
        if (count >= k) {
            ans[0] = nums[k - 1];
        }
        
        // Sliding window for the rest of the array
        for (int i = 1, j = k; j < n; i++, j++) {
            if (nums[j - 1] + 1 == nums[j]) {
                count++;
            } else {
                count = 1;
            }
            
            if (count >= k) {
                ans[i] = nums[j];
            }
        }
        
        return ans;
    }
};

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        const int n = nums.size();
        long long maxSubArraySum = 0, currWindowSum = 0;
        set<int> s; // To store unique elements in the window
        
        while (j < n) {
            // If nums[j] already exists in the set, shrink the window from the left
            while (s.count(nums[j])) {
                currWindowSum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            
            // Insert the current element into the set and update sum
            s.insert(nums[j]);
            currWindowSum += nums[j];
            
            // If window size reaches k, update max sum and shrink from left
            if (j - i + 1 == k) {
                maxSubArraySum = max(maxSubArraySum, currWindowSum);
                currWindowSum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            
            j++;
        }
        
        return maxSubArraySum;
    }
};

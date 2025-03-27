#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            // Edge case: If k is 1, no valid subarrays exist (since all elements are >=1)
            if (k <= 1) return 0;
            
            int left = 0, product = 1, count = 0;
            int n = nums.size();
            
            // Sliding window approach
            for (int right = 0; right < n; right++) {
                product *= nums[right]; // Expand the window by including nums[right]
                
                // Shrink the window from the left if product >= k
                while (product >= k) {
                    product /= nums[left];
                    left++;
                }
                
                // Count the number of subarrays ending at index 'right'
                count += (right - left + 1);
            }
            
            return count;
        }
    };
    
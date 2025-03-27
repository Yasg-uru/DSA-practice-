#include<bits/stdc++.h>
using namespace std;
class Solution { 
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            // Using a hash map (unordered_map) to store prefix sums
            unordered_map<int, int> prefixSumCount;
            int currSum = 0; // Tracks the cumulative sum of elements
            int ans = 0; // Stores the count of subarrays with sum equal to 'goal'
            
            // Initialize the map with 0 sum occurring once (for cases where subarray itself starts at index 0)
            prefixSumCount[0] = 1;
            
            // Iterate through the array
            for (int i = 0; i < nums.size(); i++) {
                currSum += nums[i]; // Update the current sum
                
                // Check if (currSum - goal) exists in the map
                // If it does, it means there exists a subarray ending at index i with sum equal to 'goal'
                if (prefixSumCount.find(currSum - goal) != prefixSumCount.end()) {
                    ans += prefixSumCount[currSum - goal]; // Add the count of such subarrays
                }
                
                // Store/update the frequency of the current prefix sum in the map
                prefixSumCount[currSum]++;
            }
            
            return ans; // Return the total count of valid subarrays
        }
    };
    





//by using the sliding window approach it is so efficient without using the extra memory 
    class Solution {
        public:
            int atMost(vector<int>& nums, int goal) {
                if (goal < 0) return 0; // Edge case: negative goal is impossible
                int left = 0, sum = 0, count = 0;
                
                for (int right = 0; right < nums.size(); right++) {
                    sum += nums[right];  // Expand the window
                    
                    while (sum > goal) { // Shrink the window if sum exceeds goal
                        sum -= nums[left];
                        left++;
                    }
                    
                    count += (right - left + 1); // Add subarrays ending at right
                }
                
                return count;
            }
            
            int numSubarraysWithSum(vector<int>& nums, int goal) {
                return atMost(nums, goal) - atMost(nums, goal - 1);
            }
        };
        
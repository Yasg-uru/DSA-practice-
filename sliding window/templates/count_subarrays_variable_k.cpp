
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Generic function to count subarrays satisfying a condition
        template <typename Condition>
        int countSubarrays(vector<int>& nums, Condition isValid) {
            unordered_map<int, int> freqMap;
            int left = 0, totalSubarrays = 0;
    
            for (int right = 0; right < nums.size(); right++) {
                // Expand the window (process nums[right])
                freqMap[nums[right]]++;
    
                // Shrink the window if it violates the condition
                while (!isValid(freqMap)) {
                    freqMap[nums[left]]--;
                    if (freqMap[nums[left]] == 0) {
                        freqMap.erase(nums[left]);
                    }
                    left++;
                }
    
                // Count subarrays ending at 'right'
                totalSubarrays += (right - left + 1);
            }
            return totalSubarrays;
        }
    
        // Specific case: Counting subarrays with exactly 'k' distinct integers
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            auto atMostK = [k](unordered_map<int, int>& freqMap) {
                return freqMap.size() <= k;
            };
            return countSubarrays(nums, atMostK) - countSubarrays(nums, [k](unordered_map<int, int>& freqMap) {
                return freqMap.size() <= k - 1;
            });
        }
    };
    
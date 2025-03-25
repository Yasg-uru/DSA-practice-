#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> mp; // Stores the elements in the current window
            int i = 0; // Left pointer of the window
    
            for (int j = 0; j < nums.size(); j++) {
                // If `nums[j]` is already in the map, we found a duplicate within `k` distance
                if (mp.count(nums[j])) {
                    return true;
                }
    
                // Insert the current element into the map
                mp[nums[j]]++;
    
                // Maintain the sliding window of size at most `k`
                if (j - i >= k) {
                    mp.erase(nums[i]); // Remove leftmost element
                    i++; // Shrink window from left
                }
            }
            return false; // No duplicate found within `k` distance
        }
    };
    
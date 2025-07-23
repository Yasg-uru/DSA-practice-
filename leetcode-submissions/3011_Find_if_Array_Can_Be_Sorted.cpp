#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // Bubble sort logic with condition to swap if adjacent elements have the same number of set bits
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                // Swap only if adjacent elements have the same number of set bits
                if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]) and nums[j]>nums[j+1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        // Check if the array is sorted after all possible swaps
        return is_sorted(nums.begin(), nums.end());
    }
};

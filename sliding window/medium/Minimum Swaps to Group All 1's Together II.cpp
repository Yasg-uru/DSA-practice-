#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int zeroes_in_currWindow = 0, total_zeroes = 0;
        int n = nums.size();
        
        // Count total number of ones in the array
        for (int num : nums) {
            if (num == 1) {
                total_zeroes++;
            }
        }
        
        int window_size = total_zeroes;
        int minSwaps = INT_MAX;
        
        // Extend the array to handle circular nature
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        
        int i = 0, j = 0;
        while (i < n) {
            zeroes_in_currWindow += nums[j];
            
            if (j - i + 1 > window_size) {
                zeroes_in_currWindow -= nums[i];
                i++;
            }
            
            if (j - i + 1 == window_size) {
                minSwaps = min(minSwaps, total_zeroes - zeroes_in_currWindow);
            }
            j++;
        }
        
        return minSwaps;
    }
};

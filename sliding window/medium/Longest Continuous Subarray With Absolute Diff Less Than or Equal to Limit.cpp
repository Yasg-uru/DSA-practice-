#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int i = 0, j = 0;
        int maxWindow = 0;
        int n = nums.size();
        
        while (j < n) {
            m.insert(nums[j]);
            
            int largest = *m.rbegin(); // Get max value in window
            int smallest = *m.begin(); // Get min value in window
            
            // Shrink window if difference exceeds limit
            while (abs(largest - smallest) > limit) {
                m.erase(m.find(nums[i]));
                largest = *m.rbegin();
                smallest = *m.begin();
                i++;
            }
            
            // Update max window size
            maxWindow = max(maxWindow, j - i + 1);
            j++;
        }
        
        return maxWindow;
    }
};
//This will give TLE 
//modified brute force--> --> --> --> --> --> -->
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end < nums.size(); ++end) {
                sum += nums[end];
                if (sum == goal)
                    ++res;
            }
        }
        return res;
    }
};
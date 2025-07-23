class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // we need to use the kadanes algorithm to solve this question 
        // 1. we need to find separate minSubarraySum and maxSubArraySum 
        // 2. and then compare their absolute values then return max of them [
        int maxSubArraySum = nums[0] ;
        int currSum =nums[0];
        for(int i=1;i<nums.size();i++){
            currSum =max(currSum+nums[i], nums[i]);
            maxSubArraySum = max(maxSubArraySum , currSum);
        }
        currSum= nums[0];
        int minSubArraySum = nums[0];
        for(int i=1;i<nums.size();i++){
            currSum =min(currSum+nums[i], nums[i]);
            minSubArraySum = min(minSubArraySum , currSum);
        }
    return max(abs(minSubArraySum), abs(maxSubArraySum));
        

    }
};
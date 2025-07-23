class Solution {
public:
    int Ka_max(vector<int>&nums ){
        int maxSum =nums[0];
        int sum = nums[0];
        for(int i =1;i<nums.size();i++){
            sum = max(sum+nums[i], nums[i]);
            maxSum = max(maxSum , sum);
        }
        return maxSum ;
    }
    
    int Ka_min(vector<int>&nums ){
        int minSum =nums[0];
        int sum = nums[0];
        for(int i =1;i<nums.size();i++){
            sum = min(sum+nums[i], nums[i]);
            minSum = min(minSum , sum);
        }
        return minSum ;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int maxSum = Ka_max(nums);
        int minSum = Ka_min(nums);
        int circular_sum = totalSum-minSum;
        if(maxSum>0){
            return max(maxSum , circular_sum);
        }
        return maxSum ;
    }
};
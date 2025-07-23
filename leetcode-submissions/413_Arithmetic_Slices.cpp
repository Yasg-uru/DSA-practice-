class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        if(dp.size()<3) return 0 ;
        int totalSlices = 0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                int prev= dp[i-1];
                dp[i]=prev+1;
                totalSlices+=prev+1; //adding current answer 
            }
        }
        return totalSlices;
    }
};
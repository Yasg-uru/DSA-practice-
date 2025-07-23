class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum =0;
        int currSum =nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                currSum+=nums[i];
            }else{
                 maxSum = max(maxSum ,currSum);
                currSum=nums[i];
            }
            maxSum = max(maxSum ,currSum);
        }
        return maxSum ;
    }
};
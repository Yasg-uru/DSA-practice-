class Solution {
public:
    bool solve(vector<int>&nums , int k ,int target){
        int n = nums.size();
        int operations=0 ;
        for(int i =0 ;i<n-1;i++){
            if(nums[i]!=target){
                nums[i]*=-1;
                nums[i+1]*=-1;
                operations++;
            }
        }
        return nums[n-1]==target && operations<=k;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        return solve(nums , k , 1) || solve(nums , k , -1);
    }
};
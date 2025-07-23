class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
      int left=0,right=0,res=0;
      while(left<nums.size()){
        if(nums[left]%2==0 and nums[left]<=threshold){
            right=left+1;
            if(right>0 and nums[right-1]%2!=nums[right] and nums[right]<=threshold){
                res=max(res,right-left);
            }
        }
      }
      return res;
    }
};
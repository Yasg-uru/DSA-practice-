class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans=0;
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            if(nums[left]<nums[left+1] and nums[right]>nums[right-1]){
                left++;
                right--;
            }
            else{
                ans=right-left+1;
                break;
            }
        }
        return ans;
    }
};
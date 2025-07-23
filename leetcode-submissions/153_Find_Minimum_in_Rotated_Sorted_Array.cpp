class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int ans;
        int high=nums.size()-1;
        while(lo<=high){
            int mid=(lo+high)/2;
            if(nums[mid+1]>nums[mid] and nums[mid]<nums[mid-1]){
                ans=nums[mid];
                break;
            }else{
                if(nums[lo]<=nums[mid]){
                    lo=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return ans;
    }
};
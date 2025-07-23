class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(mid==0){
                if(nums[mid]>nums[mid+1]){
                    return 0;
                }else{
                    return 1;
                }
            }
            if(mid==n-1){
                if(nums[mid]>nums[mid-1]){
                    return n-1;
                }else{
                    return n-2;
                }
            }
            if(nums[mid]>nums[mid-1] and nums[mid+1]<nums[mid]){
                return mid;
            }else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
};
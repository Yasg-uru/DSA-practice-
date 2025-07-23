class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int high=nums.size()-1;
        while(lo<=high){
            int mid=(lo+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[lo]<=nums[mid]){

            if(nums[lo]<=target and nums[mid]<target){
                high=mid-1;
            }else{
                lo=mid+1;
            }
            }else{
             if(nums[mid]<target and target<=nums[high]){
                lo=mid+1;
            }else{
                high=mid-1;
            }
            }
        }
        return -1;

    }
};
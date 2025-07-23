class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]<=nums[j]){
                return j-i;
            }else if(nums[i]>nums[j]){
                i++;
            }else{
                j--;
            }
        }
        return 0;
    }
};
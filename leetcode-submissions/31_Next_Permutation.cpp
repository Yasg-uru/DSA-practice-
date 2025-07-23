class Solution {
public:
    bool is_in_dec(vector<int>&nums){
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]> nums[i-1]){
                return false;
            }
        }
        return true ;
    }
    void nextPermutation(vector<int>& nums) {
        if(is_in_dec(nums)){
            sort(nums.begin(), nums.end());
            return ;
        }
        int maxEle = -1;
        int maxEle_index =-1;
        for(int i=0;i<nums.size();i++){

            if(maxEle<nums[i])
            {
                maxEle = nums[i] ;
                maxEle_index = i ;

            }
        }
        swap(nums[maxEle_index], nums[maxEle_index-1]);


    }
};
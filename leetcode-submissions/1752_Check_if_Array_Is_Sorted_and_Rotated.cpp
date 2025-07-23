class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        if(nums[0]<nums[nums.size()-1]){
            return  false;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                cnt++;

            }
            if(cnt>1){
                return false;
            }
            else if(nums[i]==nums[i+1]){
                return false;
            }
        }
        return  cnt<=1;
    }
};
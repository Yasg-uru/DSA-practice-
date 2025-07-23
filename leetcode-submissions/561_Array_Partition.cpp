class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int maxsum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+2){
       maxsum+=nums[i];
        
        }
        return maxsum;
    }
};
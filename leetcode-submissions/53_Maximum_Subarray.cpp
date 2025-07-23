class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxele=INT_MIN;
        int sumtemp=0;
        for(int i=0;i<nums.size();i++){
            sumtemp+=nums[i];
            if(maxele<sumtemp){
                maxele=sumtemp;
            }
            if(sumtemp<0){
                sumtemp=0;
            }
        }
        return maxele;
    }
};
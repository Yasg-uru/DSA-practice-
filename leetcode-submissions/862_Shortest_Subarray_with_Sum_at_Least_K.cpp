class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int minans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int currentSum=0;
            for(int j=i;j<nums.size();j++){
                currentSum+=nums[j];
                if(currentSum>=k){
                    minans=min(minans,j-i+1);
                    break;
                }
            }
        }
        return minans==INT_MAX?-1:minans;
    }
};
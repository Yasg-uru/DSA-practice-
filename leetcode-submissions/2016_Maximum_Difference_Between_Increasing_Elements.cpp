class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = INT_MIN ;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    maxDiff = max(maxDiff , nums[j]- nums[i]);
                }
            }
        }
        return maxDiff==INT_MIN?-1:maxDiff;
    }
};
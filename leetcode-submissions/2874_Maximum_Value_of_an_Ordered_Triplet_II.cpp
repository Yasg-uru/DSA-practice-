class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMax(n), rightMax(n);
        leftMax[0]=0;
        for(int i=1;i<n;i++){
            leftMax[i]= max(nums[i-1],leftMax[i-1]);
        }
        rightMax[n-1]= 0 ;
        for(int i=n-2;i>=0;i--){
            rightMax[i]= max(nums[i+1], rightMax[i+1]);
        }
        long long maxVal =0 ;
        for(int i=0;i<n;i++){
            long long val = (long long )(leftMax[i]-nums[i])*rightMax[i];
            maxVal = max(maxVal, val);
        }
        return maxVal;
        
    }
};
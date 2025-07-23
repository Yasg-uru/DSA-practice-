class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), cnt =0 ;
        
        for(int i=0;i<n-2;i++){
            int sum = nums[i]+nums[i+2];
            if(sum==(nums[i+1]/2)){
                cnt++;
            }

        }
        return cnt ;
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size(), maxAns =0 ;
        vector<vector<int>>dp(k , vector<int>(n , 1));
        // mod =0 
        // mod = 1
        // mod =2 
        // mod =3
        // ...
        // mod = k-1
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<i;j++){
                int mod = (nums[i]+nums[j])%k;
                dp[mod][i] = max(dp[mod][i], 1+dp[mod][j]);
                maxAns = max(maxAns , dp[mod][i]);
            }
        }
        return maxAns ;
    }
};
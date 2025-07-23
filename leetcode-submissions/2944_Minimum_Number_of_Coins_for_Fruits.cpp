class Solution {
public:
    int solve(int i,vector<int>&prices,vector<int>&dp){
        if(i>=prices.size()) return 0;
        int ans =INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<prices.size() && j<=i+i+1;j++){
            ans=min(ans,prices[i]+solve(j+1,prices,dp));
        }
        return dp[i]=ans;
        
    }
    int minimumCoins(vector<int>& prices) {
        vector<int>dp(prices.size(),-1);

        return solve(0,prices,dp);
    }
};
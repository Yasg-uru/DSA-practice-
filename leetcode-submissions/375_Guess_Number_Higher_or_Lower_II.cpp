class Solution {
public:
 int f(int start, int end,vector<vector<int>>&dp){
     //base case 
     if(start>=end){
         return 0;
     }
     if(dp[start][end]!=-1){
         return dp[start][end];
     }
int maxi=INT_MAX;
     //now we have a 
     for(int i=start;i<=end;i++){
     maxi=min(maxi,i+max(f(start,i-1,dp),f(i+1,end,dp)));
     }
     return dp[start][end]=maxi;
 }
    int getMoneyAmount(int n) {
        //now in these question our dp depends on the two terms 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,dp);
    }
};
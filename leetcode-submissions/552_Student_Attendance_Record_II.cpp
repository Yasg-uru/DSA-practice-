#define mod 1000000007
#define ll long long  
class Solution {
public:
int solve(int n,int absent,int late ,vector<vector<vector<ll>>>&dp){
    //base case 
    if(n==0){
        return 1;

    }
    if(dp[n][absent][late]!=-1){
        return dp[n][absent][late];

    }
    ll ans=0;
     ans=solve(n-1,absent,0,dp);
   
        ans+=(absent==0)?(solve(n-1,absent+1,0,dp)):0;
    
 
        ans+=(late<2)?(solve(n-1,absent,late+1,dp)):0;
    
    return dp[n][absent][late]=ans%mod;
}

    int checkRecord(int n) {
        //i am using dynamic programming approach for solving this question 
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(2,vector<ll>(3,-1)));
return solve(n,0,0,dp);

    }
};
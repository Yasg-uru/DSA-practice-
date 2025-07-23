class Solution {
public:
    
    set<int>denominations ;
    
   
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
       vector<int>dp(n+1 , 0);
        dp[0]= 1;
        for(int i =1;i<=n;i++){
            if(dp[i]<numWays[i-1]){
                denominations.insert(i);
                for(int j=i;j<=n;j++){
                    dp[j]+=dp[j-i];
                }
            }else if(dp[i]>numWays[i-1]){
                return {};
            }
        }
        for(int i =1;i<=n;i++){
            if(dp[i]!=numWays[i-1]){
                return {};
            }
        }
            
        return vector<int>(begin(denominations), end(denominations));
    }
};
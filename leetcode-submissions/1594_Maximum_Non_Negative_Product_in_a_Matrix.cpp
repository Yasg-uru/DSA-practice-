class Solution {
public:
    typedef long long ll;
    int m  , n ;
    int MOD = 1e9+7;
    vector<vector<pair<ll, ll>>>dp;
    pair<ll, ll> solve(int i , int j,vector<vector<int>>& grid){
       
        if(i==m-1 and j==n-1) return {grid[i][j], grid[i][j]};
        ll maxVal= LLONG_MIN;
        ll minVal= LLONG_MAX;
        if(dp[i][j] != pair<ll, ll>(LLONG_MIN, LLONG_MAX)) return dp[i][j];

        if(i+1<m){
            auto [downMax, downMin]= solve(i+1, j, grid);
            maxVal= max({maxVal, grid[i][j]*downMax, grid[i][j]*downMin});
            minVal= min({minVal, grid[i][j]*downMax, grid[i][j]*downMin});
        }
        if(j+1<n){
            auto [rightMax, rightMin]= solve(i, j+1, grid);
            maxVal= max({maxVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
            minVal= min({minVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
        }
        return dp[i][j]= {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
    m=grid.size();
    n= grid[0].size();
    dp.clear();
    dp.resize(m+1, vector<pair<ll,ll>>(n+1,{LLONG_MIN, LLONG_MAX}));
    auto [maxP, minP]=solve(0 , 0 , grid);
    return maxP<0?-1:maxP%MOD;    
    }
};
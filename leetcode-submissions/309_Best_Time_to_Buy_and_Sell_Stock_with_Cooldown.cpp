class Solution {
public:
    int n ;
    vector<vector<int>>dp;
    int solve(vector<int>&prices, int day , bool Buy){
        if(day>=n){
            return 0 ;

        }
        if(dp[day][Buy]!=-1) return dp[day][Buy];
        int maxPrice = 0 ;
        if(Buy){
            // we have two options either buy or not buy
            int take = solve(prices, day+1, false)- prices[day];
            int not_take = solve(prices, day+1, true );
            maxPrice= max({maxPrice, take , not_take});
        }else {
            // mwe have also two options either sell or not sell
            int sell= solve(prices, day+2, true)+prices[day];// we are skipping the next index because of cooldown period
            int not_sell = solve(prices, day+1, false);
            maxPrice = max({maxPrice, sell, not_sell});
        }
        return dp[day][Buy]=maxPrice;


    }
    int maxProfit(vector<int>& prices) {
        dp.clear();
        n = prices.size();
        dp.resize(n, vector<int>( 2, -1));
        return solve(prices, 0 , true);
    }
};
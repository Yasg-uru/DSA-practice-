class Solution {
public:
    int n ;
    int t[5001][2];
    int solve(vector<int>&prices, int &fee, int i , bool Buy){
        if(i>=n) return 0 ;
        int maxProfit = 0 ;
        if(t[i][Buy]!=-1) return t[i][Buy];
        if(Buy){
            int consider = solve(prices, fee, i+1, false)-prices[i];
            int not_consider = solve(prices, fee, i+1, true);
            maxProfit= max({consider, not_consider, maxProfit});
        }else{
             int consider = solve(prices, fee, i+1, true)+prices[i]-fee;
            int not_consider = solve(prices, fee, i+1, false);
            maxProfit= max({consider, not_consider, maxProfit});
        }
        return t[i][Buy]= maxProfit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n= prices.size();
        memset(t, -1, sizeof(t));
        return solve(prices , fee, 0 , true);

    }
};
class Solution {
public:
    int n ;
    vector<vector<vector<long long >>>t;
    int solve(vector<int>&prices , int k , int i , int state  ){
        if(i>=n or k==0){
            return 0 ;
            
        }
        if(t[i][k][state]!=-1){
            return t[i][k][state];
        }
        long long ans =0;
        if(state==0){
            long long buy  = -prices[i]+solve(prices , k, i+1 , 1);
            long long shortSell = prices[i]+solve(prices , k , i+1 , 2);
            long long skip = solve(prices , k , i+1 , state);
            ans = max({ans , skip , buy , shortSell});
            
        }else if (state==1){ 
            long long sell = prices[i]+solve(prices , k-1 , i+1 , 0);
            long long skip = solve(prices , k , i+1 , state );
            ans = max({ans , sell , skip});
            
        }else if (state==2){
            long long shortBuy = -prices[i]+solve(prices , k-1 , i+1 , 0);
            long long skip  = solve(prices , k , i+1 , state);
            ans = max({ans , skip ,shortBuy });
            
        }
        return t[i][k][state]= ans ;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        t.resize( n+1 , vector<vector<long long >>(k+1, vector<long long >(3, -1)));
        return solve(prices , k , 0 , 0 );
        
    }
};
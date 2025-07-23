class Solution {
public:
     int n ;
    int t[1001][101][3];
    int solve(int i , vector<int>& prices, bool isBuy , int limit){
        if(i>=n){
            return 0 ;

        }
        if(limit==0){
            return 0 ;// if limit exceeds then return zero from there 
        }
        if(t[i][limit][isBuy]!=-1){
            return t[i][limit][isBuy];
        }
        int maxP = 0 ;
        if(isBuy){
            // we can buy or not buy 
            int buy = solve(i+1, prices, false, limit )- prices[i];
            int not_buy= solve(i+1, prices, true, limit);
            maxP= max({maxP, buy , not_buy});
        }else{
            // we need to sell immediately 
            int sell = solve(i+1, prices, true, limit-1)+prices[i]; // one transaction completed
            int not_sell= solve(i+1, prices, false, limit);
            maxP= max({maxP, sell,not_sell});
        }
        return t[i][limit][isBuy]=  maxP;
    }
    int maxProfit(int k, vector<int>& prices) {
         n = prices.size();
        memset(t, -1 , sizeof(t));
        return solve(0 , prices , true , k);
    }
};
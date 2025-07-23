class Solution {
public:
vector<vector<vector<int>>>dp;
int f(int i,vector<int>&prices,int buy,int limit){
    //base cases 
    if(i==prices.size()){
        return 0;
    }
    if(limit==0){
        return 0;
    }
    if(dp[i][buy][limit]!=-1){
        return dp[i][buy][limit];
    }
    int profit=0;
    if(buy){
        int buykaro=(-prices[i]+f(i+1,prices,0,limit));
        int skipkaro=(0+f(i+1,prices,1,limit));
        profit=max(buykaro,skipkaro);
    }else{
        int sellkaro=(prices[i]+f(i+1,prices,1,limit-1));
        int skipkaro=(0+f(i+1,prices,0,limit));
        profit=max(sellkaro,skipkaro);
    }
    return dp[i][buy][limit]=profit;
}
    int maxProfit(vector<int>& prices) {
        dp.clear();
        dp.resize(100000,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,prices,1,2);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
       int maxele=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i;j<prices.size();j++){
if(prices[i]<prices[j]){
    maxele=max(prices[j],maxele);
    maxprofit=max(maxprofit,maxele-prices[i]);
}
            }
        }
        return maxprofit;
    }
};
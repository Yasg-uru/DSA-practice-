function maxProfit(prices: number[]): number {
    const dp:number[][]= new Array(prices.length+1).fill(0).map(()=>new Array(2).fill(-1));
    return solve(prices, 0 , true , dp);
};
function solve(prices:number[], i:number , isBuy:boolean, dp:number[][]): number{
    const n:number = prices.length;
    if(i>=n){
        return 0;

    }
    if(dp[i][isBuy?1:0]!==-1){
        return dp[i][isBuy?1:0];
    }
    let maxProfit:number = 0 ;
    if(isBuy){
       maxProfit = Math.max(maxProfit -prices[i]+solve(prices, i+1, false, dp));
        maxProfit  = Math.max(maxProfit , solve(prices, i+1, true, dp ));

    }else {
        maxProfit = Math.max(maxProfit,  prices[i]+solve(prices, i+1, true, dp));
        maxProfit  = Math.max(maxProfit , solve(prices, i+1, false , dp));

    }
    return dp[i][isBuy?1:0]=  maxProfit ;

}
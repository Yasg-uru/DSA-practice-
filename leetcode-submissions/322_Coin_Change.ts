function coinChange(coins: number[], amount: number): number {
    const dp :number[][] = Array.from({length:coins.length+1}, ()=>Array.from({length:amount+1}, ()=>-1));
    const ans :number = solve(coins , amount , 0, dp )

   return (ans ===Number.MAX_SAFE_INTEGER)?-1:ans;
};
function solve(coins:number[], amount:number, i :number, dp:number[][]):number {
if(amount===0){
    return  0 ;

}
if(i>=coins.length || amount<0){
    return Number.MAX_SAFE_INTEGER;
}
if(dp[i][amount]!==-1){
    return dp[i][amount];
}
const take :number = 1+ solve(coins , amount-coins[i] , i, dp);
const not_take:number = solve(coins , amount , i+1, dp);
return dp[i][amount] =  Math.min(take , not_take); 


};

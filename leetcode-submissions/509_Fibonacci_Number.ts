function fib(n: number): number {
const dp :number[]= new Array(n+1).fill(-1);
return f(n , dp);
};
function f(n :number , dp:number[]):number {
    if(n<=2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = f(n-1, dp)+f(n-2, dp);
}
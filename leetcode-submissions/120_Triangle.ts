function minimumTotal(triangle: number[][]): number {
    const n :number = triangle.length;
    const dp :number[][]  = Array.from({length:202}, ()=>Array.from({length:202}, ()=>-1));
    return solve(triangle , 0 , 0 , n, dp);
};
function solve(t:number[][], i :number , j:number , n :number, dp:number[][]):number{
    if(i===n-1){
        return t[i][j];
    }
    if(i>=n){
        return Number.MAX_SAFE_INTEGER;
    }
    if(dp[i][j]!==-1){
        return dp[i][j];
    }
    const firstRule :number = t[i][j]+solve(t, i+1, j, n , dp);
    const secondRule :number = t[i][j]+solve(t, i+1, j+1, n, dp);
    return dp[i][j] = Math.min(firstRule , secondRule);
}
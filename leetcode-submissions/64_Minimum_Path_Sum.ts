function minPathSum(grid: number[][]): number {

    const m  = grid.length , n = grid[0].length;
    const dp : Array<Array<number>> = Array.from({length:m+1}, ()=>Array.from({length:n+1}, ()=>-1));
    return solve( 0 , 0 , m , n , dp , grid);

};
function solve( i:number , j:number , m :number , n :number , dp:Array<Array<number>>, grid:Array<Array<number>>){
    if(i===m-1 && j===n-1){
        return  grid[i][j] ;

    }
    if(i<0 || j<0 || j>=n || i>=m ){
        return Number.MAX_SAFE_INTEGER;

    }
    if(dp[i][j]!==-1){
        return dp[i][j];
    }
    const downSum :number = grid[i][j]+solve(i+1 , j , m , n , dp , grid);
    const rightSum :number =  grid[i][j]+solve(i , j+1 , m , n , dp , grid);
    return dp[i][j]=Math.min(downSum , rightSum);
}

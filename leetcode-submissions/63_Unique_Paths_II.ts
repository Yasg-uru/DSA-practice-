function uniquePathsWithObstacles(grid: number[][]): number {
    const m :number = grid.length , n = grid[0].length;
    const dp : Array<number[]> = Array.from({length:m+1},()=>Array.from({length:n+1}, ()=>-1));
    return solve(m , n , 0 , 0 , dp, grid);
};
const solve=(m :number , n :number , i :number , j:number ,  dp:Array<number[]>, grid:Array<number[]>) =>{
    if(i==m-1  && j==n-1){
        return grid[i][j]==0;

    }
    
    if(i<0 || j<0 || j>=n || i>=m  || grid[i][j]==1){
        return 0 ;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=  solve(m , n , i, j+1, dp, grid)+solve(m , n , i+1, j, dp, grid);
}
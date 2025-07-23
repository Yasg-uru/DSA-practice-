function uniquePaths(m: number, n: number): number {
    const dp : Array<number[]> = Array.from({length:m+1},()=>Array.from({length:n+1}, ()=>-1));
    return solve(m , n , 0 , 0, dp);
};

const solve=(m :number , n :number , i :number , j:number ,  dp:Array<number[]>) =>{
    if(i==m-1  && j==n-1){
        return 1;

    }
    
    if(i<0 || j<0 || j>=n || i>=m  ){
        return 0 ;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=  solve(m , n , i, j+1, dp)+solve(m , n , i+1, j, dp);
}
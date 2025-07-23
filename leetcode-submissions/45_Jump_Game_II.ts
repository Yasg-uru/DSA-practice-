function jump(nums: number[]): number {
    const n : number = nums.length;
    const dp:number[]= new Array(n+1).fill(-1);

    return solve(nums , 0 , n, dp);
};

function solve(nums:number[], i : number , n:number, dp:number[] ):number {
    
    if(i>=n-1){
        return 0 ;
    }
    if(dp[i]!==-1){
        return dp[i];
    }
    let ans : number =Number.MAX_SAFE_INTEGER;
    for(let j:number =1 ;j<=nums[i];j++){
        if(i+j<n){
           ans = Math.min(ans ,  1+solve(nums , i+j , n , dp)); 
           
        }
    }
    return dp[i] =  ans;
};
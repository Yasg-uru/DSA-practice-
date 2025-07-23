function canPartition(nums: number[]): boolean {
    let totalSum :number = 0 ;
    for(const num of nums){
        totalSum+=num;
    }
    if(totalSum%2===1){
        return false;
    }
    const n :number = nums.length;
    const dp :Array<number>= new Array(n).fill(-1);
    return solve(n, nums , 0 , Number(totalSum/2), dp);

};
function solve( n :number , nums:Array<number>, i :number , halfSum:number, dp:Array<number> ){
    if(halfSum===0){
        return true ;

    }
    if(i>=n || halfSum<0){
        return false;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    return dp[i]=  solve(n , nums , i+1 , halfSum-nums[i], dp) || solve(n , nums , i+1 , halfSum, dp);


}
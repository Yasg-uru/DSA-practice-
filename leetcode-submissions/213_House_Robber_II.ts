function rob(nums: number[]): number {
    const dp1:Array<number> = new Array(nums.length+1).fill(-1);
     const dp2:Array<number> = new Array(nums.length+1).fill(-1);
    const n :number = nums.length;
    return Math.max(solve(nums , 0 , n-1,dp1), solve(nums , 1, n, dp2));
};

function solve(nums :number[], i :number , n :number , dp:Array<number>): number {
    if(i>=n){
        return 0 ;


    }
    if(dp[i]!=-1){
        return dp[i];
    }
    const take:number = nums[i]+solve(nums , i+2 , n, dp);
    const not_take:number = solve(nums , i+1, n, dp);
    return dp[i] =  Math.max(take , not_take);

};
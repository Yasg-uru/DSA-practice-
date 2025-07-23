function rob(nums: number[]): number {
    const dp :Array<number> = new Array(nums.length).fill(-1);
    return solve(nums , 0 , nums.length, dp);
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

}
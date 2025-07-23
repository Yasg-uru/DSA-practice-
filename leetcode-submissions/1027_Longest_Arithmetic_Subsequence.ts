function longestArithSeqLength(nums: number[]): number {
    const dp:Map<number , number>= new Map();
    
    let maxLength = 0, n : number = nums.length ;
    for(let i :number =0 ;i<n;i++){
        for(let j:number =i+1;j<n;j++){
            const diff:number = nums[j]-nums[i];
            maxLength = Math.max(maxLength , 2+solve(i , diff , nums, dp));
            
        }
    }
    return maxLength ;
};
function solve(i :number , d :number , nums:number[], dp:Map<number , number>):number {
    if(i<0) return 0 ;
    const key :number = i*1000+d;
    if(dp.has(key)) return dp.get(key);
    let maxAns :number =0;
    for(let k:number = i-1;k>=0;k--){
        maxAns = Math.max(maxAns , 1+solve(k , d, nums, dp));

    }
    return dp[key]=  maxAns ;
}
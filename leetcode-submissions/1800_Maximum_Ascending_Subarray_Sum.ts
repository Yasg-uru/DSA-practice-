function maxAscendingSum(nums: number[]): number {
    let currSum :number =nums[0];
    if(nums.length===1) return nums[0];
    let maxSum :number =0;
    for(let i:number =1;i<nums.length;i++){
        if(nums[i-1]<nums[i]){
            currSum+=nums[i];
        }else{
            maxSum=Math.max(maxSum,currSum);
            currSum =nums[i];
        }
        maxSum=Math.max(maxSum,currSum);
        
    }
    return maxSum;
};
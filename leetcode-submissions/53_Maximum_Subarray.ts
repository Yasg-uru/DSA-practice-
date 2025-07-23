function maxSubArray(nums: number[]): number {
    let maxSum:number=Number.MIN_SAFE_INTEGER;
    let tempSum:number=0;
    for(let i:number=0;i<nums.length;i++){
        tempSum+=nums[i];
        if(maxSum<tempSum){
            maxSum=tempSum;
        }
        if(tempSum<0){
            tempSum=0;
        }
    }
    return  maxSum;
};